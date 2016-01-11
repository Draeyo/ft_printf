/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:27:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 18:46:48 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(const char *format, va_list ap)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (format[i] == 's')
		s = va_arg(ap, char*);
	ft_putstr(s);
	return (ft_strlen(s));
}
