/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 16:23:51 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ox(p_list *lst, char *hex)
{
	if (ft_strchr(lst->tag, '#'))
	{
		str = ft_strnew(40);
		str[0] = '0';
		str[1] = 'x';
		str = ft_strjoin(str, hex);
		if (lst->conv == 'X')
			str = ft_strupper(str);
		return (str);
	}
	return (hex);
}

static int		ft_conv_hx(va_list ap, p_list *lst, char *hex)
{
	unsigned short	hhx;
	unsigned int 	hx;

	hhx = 0;
	hx = 0;
	if (ft_strstr(lst->modif, "hh"))
	{
		hhx = va_arg(ap, unsigned int);
		hex = ft_itohex(hhx);
		return (hex);
	}
	else if (ft_strstr(lst->modif, "h"))
	{
		hx = va_arg(ap, unsigned short);
		hex = ft_itohex(hx);
		return (hex);
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
		hhx = va_arg(ap, unsigned long long);
		hex = ft_lltohex(hhx);
		return (hex);
	}
	else if (ft_strstr(lst->modif, "l"))
	{
		hx = va_arg(ap, unsigned long);
		hex = ft_lltohex(hx);
		return (hex);
	}
	return (-1);
}

int		ft_conv_x(va_list ap, p_list *lst)
{
	int		x;
	char	*hex;

	x = 0;
	hex = ft_strnew(30);
	if (lst->conv == 'x' || lst->conv == 'X')
	{
		x = va_arg(ap, int);
		hex = ft_itohex(x);
		hex = ft_ox(lst, hex); 
	}
	else if ((count = ft_conv_hx(ap, lst, hex)) > 0)
		hex = ft_ox(lst, hex); 
	else if ((count - ft_conv_lx(ap, lst, hex)) > 0)
		hex = ft_ox(lst, hex);
	ft_putstr(hex);
	free(hex);
	return (ft_strlen(hex));
}
