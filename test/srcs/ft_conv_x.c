/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 20:27:18 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_x(const char *format, va_list ap)
{
	int		i;
	int		x;
	char	*hex;

	i = 0;
	x = 0;
	hex = ft_strnew(30);
	if (format[i] == 'x' || format[i] == 'X')
	{
		x = va_arg(ap, int);
		hex = ft_itohex(x);
	}
	if (format[i] == 'X')
		hex = ft_strupper(hex);
	ft_putstr(hex);
	return (ft_strlen(hex));
}
