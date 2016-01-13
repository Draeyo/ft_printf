/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 14:58:04 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_o(const char *format, va_list ap)
{
	int				i;
	unsigned int	o;

	i = 0;
	o = 0;
	if (format[i] == 'o' || format[i] == 'O')
		o = va_arg(ap, unsigned int);
	ft_putnbo(o);
	return (ft_nblen(o));
}
