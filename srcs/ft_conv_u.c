/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/24 17:22:48 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzu(va_list ap, p_list *lst, char *str)
{
	uintmax_t	ju;
	size_t		zu;
	char			*stock = NULL;

	ju = 0;
	zu = 0;
	if (ft_strstr(lst->modif, "j"))
	{
		ju = va_arg(ap, uintmax_t);
		stock = ft_s_ulltoa(ju);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(stock)),
			ft_prec(lst, ft_strlen(stock)), stock, lst)));
		return (ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "z"))
	{
		zu = va_arg(ap, size_t);
		stock = ft_s_ulltoa((unsigned long long) zu);
		ft_putstr((str = ft_padding(ft_width(lst, ft_strlen(stock)),
			ft_prec(lst, ft_strlen(stock)), stock, lst)));
		return (ft_strlen(str));
	}
	return (-1);
}

static int		ft_conv_hu(va_list ap, p_list *lst, char *str)
{
	unsigned char	hhu;
	unsigned short	hu;

	hhu = 0;
	hu = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhu = va_arg(ap, unsigned int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_unblen(hhu)),
					ft_prec(lst, ft_unblen(hhu)), ft_s_itoa(hhu), lst)));
		return (ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hu = va_arg(ap, unsigned int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_unblen(hu)),
					ft_prec(lst, ft_unblen(hu)), ft_s_itoa(hu), lst)));
		return (ft_strlen(str));
	}
	return (-1);
}

static int		ft_conv_lu(va_list ap, p_list *lst, char *str)
{
	unsigned long long	llu;
	unsigned long		lu;

	llu = 0;
	lu = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llu = va_arg(ap, unsigned long long);
		ft_putstr((str = ft_padding(ft_width(lst, ft_ullnblen(llu)),
					ft_prec(lst, ft_ullnblen(llu)), ft_s_lltoa(llu), lst)));
		return (ft_strlen(str));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lu = va_arg(ap, unsigned long);
		ft_putstr((str = ft_padding(ft_width(lst, ft_ullnblen(lu)),
					ft_prec(lst, ft_ullnblen(lu)), ft_s_lltoa(lu), lst)));
		return (ft_strlen(str));
	}
	return (-1);
}

int				ft_conv_u(va_list ap, p_list *lst)
{
	int		u;
	int		count;
	char	*str = NULL;

	u = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'u' || lst->conv == 'U'))
	{
		u = va_arg(ap, unsigned int);
		ft_putstr((str = ft_padding(ft_width(lst, ft_unblen(u)),
					ft_prec(lst, ft_unblen(u)), ft_s_uitoa(u), lst)));
	}
	else if ((count = ft_conv_hu(ap, lst, str)) > 0)
		return (count);
	else if ((count = ft_conv_lu(ap, lst, str)) > 0)
		return (count);
	else if ((count = ft_conv_jzu(ap, lst, str)) > 0)
		return (count);
	return (ft_strlen(str));
}
