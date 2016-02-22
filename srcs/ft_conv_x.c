/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/20 15:39:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ox(p_list *lst, char *hex)
{
	char	str[] = "0x";

	if (ft_strchr(lst->flag, '#'))
	{
		if (lst->prec)
			lst->width -= 2;
		if ((lst->prec - (int)ft_strlen(hex)) <= 0)
			hex = ft_strjoin(str, hex);
	}
	hex = ft_padding(ft_width(lst, ft_strlen(hex)), ft_prec(lst, ft_strlen(hex)), hex, lst);
	if (lst->conv == 'X')
		hex = ft_xupper(hex);
	return (hex);
}

static int		ft_conv_hx(va_list ap, p_list *lst, char *hex)
{
	unsigned char	hhx;
	unsigned short	hx;

	hhx = 0;
	hx = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhx = va_arg(ap, unsigned int);
		hex = ft_itohex(hhx);
		ft_putstr((hex = ft_ox(lst, hex)));
		free(hex);
		return (ft_strlen(hex));
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hx = va_arg(ap, unsigned int);
		hex = ft_itohex(hx);
		ft_putstr((hex = ft_ox(lst, hex)));
		free(hex);
		return (ft_strlen(hex));
	}
	return (-1);
}

static int		ft_conv_lx(va_list ap, p_list *lst, char *hex)
{
	unsigned long long	llx;
	unsigned long		lx;

	llx = 0;
	lx = 0;
	if (ft_strstr(lst->modif, "ll"))
	{
		llx = va_arg(ap, unsigned long long);
		hex = ft_lltohex(llx);
		ft_putstr((hex = ft_ox(lst, hex)));
		free(hex);
		return (ft_strlen(hex));
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		lx = va_arg(ap, unsigned long);
		hex = ft_lltohex(lx);
		ft_putstr((hex = ft_ox(lst, hex)));
		free(hex);
		return (ft_strlen(hex));
	}
	return (-1);
}

int				ft_conv_x(va_list ap, p_list *lst)
{
	int		x;
	char	*hex;
	int		count;

	x = 0;
	count = 0;
	hex = ft_strnew(30);
	if (lst->modif == NULL && (lst->conv == 'x' || lst->conv == 'X'))
	{
		x = va_arg(ap, int);
		hex = ft_itohex(x);
		ft_putstr((hex = ft_ox(lst, hex)));
	}
	else if ((count = ft_conv_hx(ap, lst, hex)) > 0)
		return (count);
	else if ((count = ft_conv_lx(ap, lst, hex)) > 0)
		return (count);
	free(hex);
	return (ft_strlen(hex));
}
