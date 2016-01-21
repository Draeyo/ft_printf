/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 15:21:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_hd(va_list ap, p_list *lst)
{
	int		c;
	int		s;

	if (ft_strstr(lst->modif, "hh") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		c = va_arg(ap, int);
		ft_putnbr(c);
		return (1);
	}
	else if (ft_strstr(lst->modif, "h") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		s = va_arg(ap, int);
		ft_putnbr(s);
		return (ft_nblen(s));
	}
	return (-1);
}

static int		ft_conv_ld(va_list ap, p_list *lst)
{
	long		ld;
	long long	lld;

	ld = 0;
	lld = 0;
	if (ft_strstr(lst->modif, "ll") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		lld = va_arg(ap, long long);
		ft_putlong(lld);
		return (ft_llnblen(lld));
	}
	else if (ft_strstr(lst->modif, "l") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		ld = va_arg(ap, long);
		ft_putlong(ld);
		return (ft_nblen(ld));
	}
	return (-1);
}

int		ft_conv_d(va_list ap, p_list *lst)
{
	int				d;
	unsigned int	ud;
	int				count;

	d = 0;
	ud = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'd' || lst->conv == 'i'))
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		return (ft_nblen(d));
	}
	else if (lst->modif == NULL && lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		ft_putlong(ud);
		return (ft_unblen(ud));
	}
	if ((count = ft_conv_hd(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_ld(ap, lst)) > 0)
		return (count);
	return (0);
}

