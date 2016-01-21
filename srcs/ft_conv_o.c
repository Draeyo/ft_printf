/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 16:47:07 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_ho(va_list ap, p_list *lst)
{
	unsigned int	hho;
	unsigned short 	ho;

	hho = 0;
	ho = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hho = va_arg(ap, unsigned int);
		hho = itoo(hho);
		ft_putlong(hho);
		return (ft_unblen(hho));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		ho = va_arg(ap, unsigned short);
		hho = ft_itoo(ho);
		ft_putlong(hho);
		return (ft_unblen(hho));
	}
	return (-1);
}

static int		ft_conv_lo(va_list ap, p_list *lst)
{
	unsigned long long	llo;
	unsigned long		lo;

	llo = 0;
	lo = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		llo = ft_lltoo(llo);
		ft_putlong(llo);
		return (ft_llnblen(llo));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lo = va_arg(ap, unsigned long);
		llo = ft_lltoo((unsigned long long)lo);
		ft_putlong(llo);
		return (ft_llnblen(llo));
	}
	return (-1);
}

int		ft_conv_o(va_list ap, p_list *lst)
{
	unsigned int	o;
	int 			count;

	o = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'o' || lst->conv == 'O'))
	{
		o = va_arg(ap, unsigned int);
		ft_putnbo(o);
		return (ft_nblen(o));
	}
	else if ((count = ft_conv_ho(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_lo(ap, lst)) > 0)
		return (count);
	return (0);
}
