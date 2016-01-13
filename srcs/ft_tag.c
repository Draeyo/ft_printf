/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:28:09 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 14:54:47 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** creer code de conversion du tag ?
*/

int		ft_tag(const char *format, va_list ap)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (format[i] == '%')
		j = ft_noconv(&format[i]);
	else if (format[i] == 's')
		j = ft_conv_s(&format[i], ap);
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'D')
		j = ft_conv_d(&format[i], ap);
	else if (format[i] == 'x' || format[i] == 'X')
		j = ft_conv_x(&format[i], ap);
	else if (format[i] == 'c')
		j = ft_conv_c(&format[i], ap);
	else if (format[i] == 'o' || format[i] == 'O')
		j = ft_conv_o(&format[i], ap);
	else if (format[i] == 'p')
		j = ft_conv_p(&format[i], ap);
	else if (format[i] == 'S')
		j = ft_conv_ws(&format[i], ap);
	else if (format[i] == 'C')
		j = ft_conv_wc(&format[i], ap);
	else if (format[i] == 'u' || format[i] == 'U')
		j = ft_conv_u(&format[i], ap);
	return (j);
}
