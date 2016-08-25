/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/25 15:10:15 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzo(va_list ap, t_print *lst)
{
	uintmax_t	jo;
	size_t		zo;

	jo = 0;
	zo = 0;
	if (MODIF && ft_strstr(MODIF, "j"))
	{
		jo = va_arg(ap, uintmax_t);
		return (ft_padding_str(lst, ft_uitooa(jo)));
	}
	else if (MODIF && ft_strstr(MODIF, "z"))
	{
		zo = va_arg(ap, size_t);
		return (ft_padding_str(lst, ft_uitooa(zo)));
	}
	return (-1);
}

static int		ft_conv_ho(va_list ap, t_print *lst)
{
	unsigned char	hho;
	unsigned short	ho;

	hho = 0;
	ho = 0;
	if (MODIF && ft_strstr(MODIF, "hh"))
	{
		hho = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, ft_itoo(hho)));
	}
	else if (MODIF && ft_strstr(MODIF, "h"))
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
	if (MODIF && ft_strstr(MODIF, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		return (ft_padding_str(lst, ft_uitooa(llo)));
	}
	else if ((MODIF && ft_strstr(MODIF, "l")) || CONV == 'O')
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
	if (!MODIF && CONV == 'o')
	{
		o = va_arg(ap, unsigned int);
		if (o == 0 && ZEROP)
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
