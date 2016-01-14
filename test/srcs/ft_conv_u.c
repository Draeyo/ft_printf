/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 15:05:36 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_u(const char *format, va_list ap)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	if (format[i] == 'u' || format[i] == 'U')
		u = va_arg(ap, unsigned int);
	ft_putlong(u);
	return (ft_nblen(u));
}
