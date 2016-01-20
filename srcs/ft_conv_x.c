/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/20 15:24:48 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(va_list ap, p_list *lst)
{
	int		i;
	int		x;
	char	*hex;

	i = 0;
	x = 0;
	hex = ft_strnew(30);
	if (ft_strchr(lst->tag, '#') != NULL && lst->conv == 'x')
		ft_putstr("0x");
	else if (ft_strchr(lst->tag, '#') != NULL && lst->conv == 'X')
		ft_putstr("0X");
	if (lst->conv == 'x' || lst->conv == 'X')
	{
		x = va_arg(ap, int);
		hex = ft_itohex(x);
	}
	if (lst->conv == 'X')
		hex = ft_strupper(hex);
	ft_putstr(hex);
	return (ft_strlen(hex));
}
