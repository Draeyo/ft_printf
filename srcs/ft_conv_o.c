/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/22 14:43:45 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzo(va_list ap, t_print *lst)
{
	uintmax_t	jo;
	size_t		zo;

	jo = 0;
	zo = 0;
	if (lst->modif && ft_strstr(lst->modif, "j"))
	{
		jo = va_arg(ap, uintmax_t);
		return (ft_padding_str(lst, ft_uitooa(jo)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "z"))
	{
		zo = va_arg(ap, size_t);
		return(ft_padding_str(lst, ft_uitooa(zo)));
	}
	return (-1);
}

static int		ft_conv_ho(va_list ap, t_print *lst)
{
	unsigned char	hho;
	unsigned short	ho;

	hho = 0;
	ho = 0;
	if (lst->modif && ft_strstr(lst->modif, "hh"))
	{
		hho = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, ft_itoo(hho)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "h"))
	{
		ho = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, ft_itoo(ho)));
	}
	return (-1);
}

static int		ft_conv_lo(va_list ap, t_print *lst)
{
	unsigned long long	llo;
	unsigned long		lo;

	llo = 0;
	lo = 0;
	if (lst->modif && ft_strstr(lst->modif, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		return (ft_padding_str(lst, ft_uitooa(llo)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "l"))
	{
		lo = va_arg(ap, unsigned long);
		return (ft_padding_str(lst, ft_uitooa(lo)));
	}
	return (-1);
}

int				ft_conv_o(va_list ap, t_print *lst)
{
	unsigned int	o;
	int				count;

	o = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'o' || lst->conv == 'O'))
	{
		o = va_arg(ap, unsigned int);
		if (o == 0 && lst->zeroprec)
			return (ft_padding_str(lst, ""));
		return (ft_padding_str(lst, ft_uitooa(o)));
	}
	else if ((count = ft_conv_ho(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_lo(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_jzo(ap, lst)) > 0)
		return (count);
	return (0);
}
