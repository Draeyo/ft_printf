/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/10 16:30:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_ho(va_list ap, p_list *lst)
{
	unsigned char		hho;
	unsigned short 	ho;
	int							stock;

	hho = 0;
	ho = 0;
	stock = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hho = va_arg(ap, unsigned int);
		stock = ft_itoo(hho);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(stock))), ft_prec(lst, ft_strlen(ft_s_itoa(stock))), ft_s_itoa(stock), lst));
		return (ft_unblen(stock));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		ho = va_arg(ap, unsigned int);
		stock = ft_itoo(ho);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(stock))), ft_prec(lst, ft_strlen(ft_s_itoa(stock))), ft_s_itoa(stock), lst));
		return (ft_unblen(stock));
	}
	return (-1);
}

static int		ft_conv_lo(va_list ap, p_list *lst)
{
	unsigned long long	llo;
	unsigned long		lo;
	char						*stock;

	llo = 0;
	lo = 0;
	stock = NULL;
	if (ft_strstr(lst->modif, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		stock = ft_lltoo(llo);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(stock)), ft_prec(lst, ft_strlen(stock)), stock, lst));
		return (ft_llnblen(llo));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lo = va_arg(ap, unsigned long);
		stock = ft_lltoo((unsigned long long)lo);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(stock)), ft_prec(lst, ft_strlen(stock)), stock, lst));
		return (ft_llnblen(llo));
	}
	return (-1);
}

int		ft_conv_o(va_list ap, p_list *lst)
{
	unsigned int	o;
	int 			count;
	char			*stock;

	o = 0;
	count = 0;
	stock = NULL;
	if (lst->modif == NULL && (lst->conv == 'o' || lst->conv == 'O'))
	{
		o = va_arg(ap, unsigned int);
		stock = ft_putnbo(o);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(stock)), ft_prec(lst, ft_strlen(stock)), stock, lst));
		return (ft_nblen(o));
	}
	else if ((count = ft_conv_ho(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_lo(ap, lst)) > 0)
		return (count);
	return (0);
}
