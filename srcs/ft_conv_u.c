/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 16:37:30 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_hu(va_list ap, p_list *lst)
{
	unsigned int	hhu;
	unsigned short 	hu;

	hhu = 0;
	hu = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhu = va_arg(ap, unsigned int);
		ft_put_unsigned_int(hhu);
		return(ft_nblen(hhu));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hu = va_arg(ap, unsigned short);
		ft_putnbr(hu);
		return (ft_nblen(hu));
	}
	return (-1);
}

static int		ft_conv_lu(va_list ap, p_list *lst)
{
	unsigned long long	llo;
	unsigned long 		lo;

	llo = 0;
	lo = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		ft_putlong(llo);
		return (ft_llnblen(llo));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lo = va_arg(ap, unsigned long);
		ft_putlong(lo);
		return (ft_llnblen(lo));
	}
	return (-1);
}

int		ft_conv_u(va_list ap, p_list *lst)
{
	int		u;
	int		count;

	u = 0;
	count = 0;
	if (lst->conv == 'u' || lst->conv == 'U')
	{
		u = va_arg(ap, unsigned int);
		ft_put_unsigned_int(u);
	}
	else if ((count = ft_conv_hu(ap, lst)) > 0)
		return (count);
	else if ((coutn = ft_conv_lu(ap, lst)) > 0)
		return (count);
	return (ft_nblen(u));
}
