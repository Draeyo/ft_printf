/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 13:14:31 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzd(va_list ap, p_list *lst)
{
	intmax_t	jd;
	long long zd;

	jd = 0;
	zd = 0;
	if (ft_strstr(lst->modif, "j"))
	{
		jd = va_arg(ap, intmax_t);
		return(ft_padding_int(lst, jd));
	}
	else if (ft_strstr(lst->modif, "z"))
	{
		zd = va_arg(ap, long long);
		return(ft_padding_int(lst, zd));
	}
	return (-1);
}

static int		ft_conv_hd(va_list ap, p_list *lst)
{
	char		c;
	short		s;

	if (ft_strstr(lst->modif, "hh") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		c = va_arg(ap, int);
		return (ft_padding_int(lst, (int)c));
	}
	else if (ft_strstr(lst->modif, "h") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		s = va_arg(ap, int);
		return (ft_padding_int(lst, s));
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
		return (ft_padding_int(lst, lld));
	}
	else if (ft_strstr(lst->modif, "l") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		ld = va_arg(ap, long);
		return (ft_padding_int(lst, ld));
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
		return (ft_padding_int(lst, d));
	}
	else if (lst->modif == NULL && lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		return (ft_padding_str(lst, ft_s_uitoa(ud)));
	}
	if ((count = ft_conv_hd(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_ld(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_jzd(ap, lst)) > 0)
		return (count);
	return (0);
}
