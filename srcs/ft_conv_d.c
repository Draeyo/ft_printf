/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/22 16:08:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzd(va_list ap, p_list *lst, char *str)
{
	intmax_t	jd;
	long long jz;

	jd = 0;
	jz = 0;
	if (ft_strstr(lst->modif, "j"))
	{
		jd = va_arg(ap, intmax_t);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(jd))),
				ft_prec(lst, ft_strlen(ft_s_ltoa(jd))), ft_s_ltoa(jd), lst)));
		return(ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "z"))
	{
		jz = va_arg(ap, long long);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_lltoa(jd))),
				ft_prec(lst, ft_strlen(ft_s_lltoa(jd))), ft_s_lltoa(jd), lst)));
		return(ft_strlen(str));
	}
	return (-1);
}

static int		ft_conv_hd(va_list ap, p_list *lst, char *str)
{
	char		c;
	short		s;

	if (ft_strstr(lst->modif, "hh") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		c = va_arg(ap, int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(c))),
					ft_prec(lst, ft_strlen(ft_s_itoa(c))), ft_s_itoa(c), lst)));
		return (ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "h") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		s = va_arg(ap, int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(s))),
					ft_prec(lst, ft_strlen(ft_s_itoa(s))), ft_s_itoa(s), lst)));
		return (ft_strlen(str));
	}
	return (-1);
}

static int		ft_conv_ld(va_list ap, p_list *lst, char *str)
{
	long		ld;
	long long	lld;

	ld = 0;
	lld = 0;
	if (ft_strstr(lst->modif, "ll") && (lst->conv == 'd' || lst->conv == 'i'))
	{
		lld = va_arg(ap, long long);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(lld))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(lld))),
						ft_s_ltoa(lld), lst)));
		return (ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "l") && (lst->conv == 'd'
				|| lst->conv == 'i'))
	{
		ld = va_arg(ap, long);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(ld))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(ld))),
						ft_s_ltoa(ld), lst)));
		return (ft_strlen(str));
	}
	return (-1);
}

int				ft_conv_d(va_list ap, p_list *lst)
{
	int				d;
	unsigned int	ud;
	int				count;
	char			*str = NULL;

	d = 0;
	ud = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'd' || lst->conv == 'i'))
	{
		d = va_arg(ap, int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_itoa(d))),
					ft_prec(lst, ft_strlen(ft_s_itoa(d))), ft_s_itoa(d), lst)));
		return (ft_strlen(str));
	}
	else if (lst->modif == NULL && lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(ft_s_ltoa(ud))),
					ft_prec(lst, ft_strlen(ft_s_ltoa(ud))),
						ft_s_ltoa(ud), lst)));
		return (ft_strlen(str));
	}
	if ((count = ft_conv_hd(ap, lst, str)) > 0)
		return (count);
	else if ((count = ft_conv_ld(ap, lst, str)) > 0)
		return (count);
	else if ((count = ft_conv_jzd(ap, lst, str)) > 0)
		return (count);
	return (0);
}
