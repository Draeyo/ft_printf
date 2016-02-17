/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:06:30 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_hd(va_list ap, p_list *lst)
{
	char		c;
	short		s;

	if (ft_strstr(lst->modif, "hh") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		c = va_arg(ap, int);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(c))),
					ft_prec(lst, ft_strlen(ft_s_itoa(c))), ft_s_itoa(c), lst));
		return (1);
	}
	else if (ft_strstr(lst->modif, "h") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		s = va_arg(ap, int);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(s))),
					ft_prec(lst, ft_strlen(ft_s_itoa(s))), ft_s_itoa(s), lst));
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
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(lld))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(lld))),
						ft_s_ltoa(lld), lst));
		return (ft_llnblen(lld));
	}
	else if (ft_strstr(lst->modif, "l") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		ld = va_arg(ap, long);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(ld))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(ld))),
						ft_s_ltoa(ld), lst));
		return (ft_nblen(ld));
	}
	return (-1);
}

int				ft_conv_d(va_list ap, p_list *lst)
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
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(d))),
					ft_prec(lst, ft_strlen(ft_s_itoa(d))), ft_s_itoa(d), lst));
		return (ft_nblen(d));
	}
	else if (lst->modif == NULL && lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(ud))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(ud))),
						ft_s_ltoa(ud), lst));
		return (ft_unblen(ud));
	}
	if ((count = ft_conv_hd(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_ld(ap, lst)) > 0)
		return (count);
	return (0);
}
