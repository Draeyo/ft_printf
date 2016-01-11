/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:58:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 20:11:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_ws(const char *format, va_list ap)
{
	int			i;
	wchar_t		*wstr;

	i = 0;
	wstr = (wchar_t*)malloc(sizeof(*wstr) * 50);
	if (format[i] == 'S')
		wstr = va_arg(ap, wchar_t*);
	ft_putwstr(wstr);
	return (ft_wstrlen(wstr));
}

int		ft_conv_wc(const char *format, va_list ap)
{
	int			i;
	wint_t		wint;
	wchar_t		wbuf;

	i = 0;
	wint = 0;
	if (format[i] == 'C')
		wint = va_arg(ap, wint_t);
	wbuf = wint;
	write(1, &wbuf, 4);
	return (1);
}
