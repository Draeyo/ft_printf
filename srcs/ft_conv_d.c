/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 14:28:15 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzd(va_list ap, t_print *lst)
{
	intmax_t	jd;
	long long	zd;

	jd = 0;
	zd = 0;
	if (lst->modif && ft_strstr(lst->modif, "j"))
	{
		jd = va_arg(ap, intmax_t);
		return (ft_padding_int(lst, jd));
	}
	else if (lst->modif && ft_strstr(lst->modif, "z"))
	{
		zd = va_arg(ap, long long);
		return (ft_padding_int(lst, zd));
	}
	return (-1);
}

static int		ft_conv_hd(va_list ap, t_print *lst)
{
	char		c;
	short		s;

	if (lst->modif && ft_strstr(lst->modif, "hh"))
	{
		c = va_arg(ap, int);
		return (ft_padding_int(lst, (int)c));
	}
	else if (lst->modif && ft_strstr(lst->modif, "h"))
	{
		s = va_arg(ap, int);
		return (ft_padding_int(lst, s));
	}
	return (-1);
}

static int		ft_conv_ld(va_list ap, t_print *lst)
{
	long		ld;
	long long	lld;

	ld = 0;
	lld = 0;
	if (lst->modif && ft_strstr(lst->modif, "ll"))
	{
		lld = va_arg(ap, long long);
		return (ft_padding_int(lst, lld));
	}
	else if (lst->modif && ft_strstr(lst->modif, "l"))
	{
		ld = va_arg(ap, long);
		return (ft_padding_int(lst, ld));
	}
	return (-1);
}

int				ft_conv_d(va_list ap, t_print *lst)
{
	int				d;
	unsigned int	ud;

	d = 0;
	ud = 0;
	if (lst->modif == NULL && (lst->conv == 'd' || lst->conv == 'i'))
	{
		d = va_arg(ap, int);
		if (d == 0 && lst->zeroprec)
			return (ft_padding_str(lst, ""));
		return (ft_padding_int(lst, d));
	}
	else if (lst->modif == NULL && lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		return (ft_padding_str(lst, ft_uxtoa(ud)));
	}
	if ((COUNT = ft_conv_hd(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_ld(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_jzd(ap, lst)) > 0)
		return (COUNT);
	return (0);
}
