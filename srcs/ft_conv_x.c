/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 14:29:33 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzx(va_list ap, t_print *lst)
{
	uintmax_t	jx;
	size_t		zx;

	jx = 0;
	zx = 0;
	if (lst->modif && ft_strstr(lst->modif, "j"))
	{
		jx = va_arg(ap, uintmax_t);
		return (ft_padding_str(lst, ft_itohex(jx)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "z"))
	{
		zx = va_arg(ap, size_t);
		return (ft_padding_str(lst, ft_itohex(zx)));
	}
	return (-1);
}

static int		ft_conv_hx(va_list ap, t_print *lst)
{
	unsigned char	hhx;
	unsigned short	hx;

	hhx = 0;
	hx = 0;
	if (lst->modif && ft_strstr(lst->modif, "hh"))
	{
		hhx = va_arg(ap, unsigned int);
		return (ft_padding_str(lst, ft_itohex(hhx)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "h"))
	{
		hx = va_arg(ap, unsigned int);
		return (ft_padding_str(lst, ft_itohex(hx)));
	}
	return (-1);
}

static int		ft_conv_lx(va_list ap, t_print *lst)
{
	unsigned long long	llx;
	unsigned long		lx;

	llx = 0;
	lx = 0;
	if (lst->modif && ft_strstr(lst->modif, "ll"))
	{
		llx = va_arg(ap, unsigned long long);
		return (ft_padding_str(lst, ft_itohex(llx)));
	}
	else if (lst->modif && ft_strstr(lst->modif, "l"))
	{
		lx = va_arg(ap, unsigned long);
		return (ft_padding_str(lst, ft_itohex(lx)));
	}
	return (-1);
}

int				ft_conv_x(va_list ap, t_print *lst)
{
	unsigned int	x;

	x = 0;
	if (ft_strchr(lst->flag, '#') && lst->conv == 'x')
		lst->hex = "0x";
	else if (ft_strchr(lst->flag, '#') && lst->conv == 'X')
		lst->hex = "0X";
	if (lst->modif == NULL && (lst->conv == 'x' || lst->conv == 'X'))
	{
		x = va_arg(ap, unsigned int);
		if (x == 0 && lst->zeroprec)
		{
			lst->hex = "";
			return (ft_padding_str(lst, ""));
		}
		return (ft_padding_str(lst, ft_itohex(x)));
	}
	else if ((COUNT = ft_conv_hx(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_lx(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_jzx(ap, lst)) > 0)
		return (COUNT);
	return (0);
}
