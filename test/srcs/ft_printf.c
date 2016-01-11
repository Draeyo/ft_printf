/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:22:42 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 18:56:08 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	ap;

	i = 0;
	j = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j += ft_tag(&format[i], ap);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			j++;
			i++;
		}
	}
	va_end(ap);
	return (j);
}
