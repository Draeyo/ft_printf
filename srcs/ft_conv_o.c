/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 18:50:45 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_o(const char *format, va_list ap)
{
	int		i;
	int		o;

	i = 0;
	o = 0;
	if (format[i] == 'o')
		o = va_arg(ap, int);
	o = ft_itoo(o);
	ft_putnbr(o);
	return (ft_nblen(o));
}
