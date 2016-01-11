/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:40:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 18:50:21 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(const char *format, va_list ap)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (format[i] == 'c')
		c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}
