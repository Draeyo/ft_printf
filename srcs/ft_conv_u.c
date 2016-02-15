/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/15 16:17:36 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_hu(va_list ap, p_list *lst)
{
	unsigned char	hhu;
	unsigned short 	hu;

	hhu = 0;
	hu = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhu = va_arg(ap, unsigned int);
		ft_putstr(ft_padding(ft_width(lst, ft_unblen(hhu)), ft_prec(lst, ft_unblen(hhu)), ft_s_itoa(hhu), lst));
		return(ft_nblen(hhu));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hu = va_arg(ap, unsigned int);
		ft_putstr(ft_padding(ft_width(lst, ft_unblen(hu)), ft_prec(lst, ft_unblen(hu)), ft_s_itoa(hu), lst));
		return (ft_nblen(hu));
	}
	return (-1);
}

static int		ft_conv_lu(va_list ap, p_list *lst)
{
	unsigned long long	llu;
	unsigned long 		lu;

	llu = 0;
	lu = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llu = va_arg(ap, unsigned long long);
		ft_putstr(ft_padding(ft_width(lst, ft_ullnblen(llu)), ft_prec(lst, ft_ullnblen(llu)), ft_s_lltoa(llu), lst));
		return (ft_llnblen(llu));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lu = va_arg(ap, unsigned long);
		ft_putstr(ft_padding(ft_width(lst, ft_ullnblen(lu)), ft_prec(lst, ft_ullnblen(lu)), ft_s_lltoa(lu), lst));
		return (ft_llnblen(lu));
	}
	return (-1);
}

int		ft_conv_u(va_list ap, p_list *lst)
{
	int		u;
	int		count;

	u = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'u' || lst->conv == 'U'))
	{
		u = va_arg(ap, unsigned int);
		ft_putstr(ft_padding(ft_width(lst, ft_unblen(u)), ft_prec(lst, ft_unblen(u)), ft_s_uitoa(u), lst));
	}
	else if ((count = ft_conv_hu(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_lu(ap, lst)) > 0)
		return (count);
	return (ft_nblen(u));
}
