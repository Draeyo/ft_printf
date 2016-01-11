/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 19:14:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_d(const char *format, va_list ap)
{
	int				i;
	int				d;
	unsigned int 	ud;

	i = 0;
	d = 0;
	if (format[i] == 'd' || format[i] == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		return (ft_nblen(d));
	}
	else if (format[i] == 'D')
	{
		ud = va_arg(ap, unsigned int);
		ft_putlong(ud);
		return (ft_nblen(ud));
	}
	return (0);
}
