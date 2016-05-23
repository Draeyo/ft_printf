/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 13:48:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzu(va_list ap, p_list *lst)
{
	uintmax_t	ju;
	size_t		zu;

	ju = 0;
	zu = 0;
	if (ft_strstr(lst->modif, "j"))
	{
		ju = va_arg(ap, uintmax_t);
		return (ft_padding_uint(lst, ju));
	}
	else if (ft_strstr(lst->modif, "z"))
	{
		zu = va_arg(ap, size_t);
		return (ft_padding_uint(lst, zu));
	}
	return (-1);
}

static int		ft_conv_hu(va_list ap, p_list *lst)
{
	unsigned char	hhu;
	unsigned short	hu;

	hhu = 0;
	hu = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhu = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, hhu));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hu = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, hu));
	}
	return (-1);
}

static int		ft_conv_lu(va_list ap, p_list *lst)
{
	unsigned long long	llu;
	unsigned long		lu;

	llu = 0;
	lu = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llu = va_arg(ap, unsigned long long);
		return (ft_padding_uint(lst, llu));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lu = va_arg(ap, unsigned long);
		return (ft_padding_uint(lst, lu));
	}
	return (-1);
}

int				ft_conv_u(va_list ap, p_list *lst)
{
	unsigned int		u;
	int		count;

	u = 0;
	count = 0;
	if (lst->modif == NULL && (lst->conv == 'u' || lst->conv == 'U'))
	{
		u = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, u));
	}
	else if ((count = ft_conv_hu(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_lu(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_jzu(ap, lst)) > 0)
		return (count);
	return (0);
}
