/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:58:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:22:53 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_ws(va_list ap, p_list *lst)
{
	int			i;
	wchar_t		*wstr;

	i = 0;
	wstr = (wchar_t*)malloc(sizeof(*wstr) * 50);
	if (lst->conv == 'S')
		wstr = va_arg(ap, wchar_t*);
	ft_putwstr(wstr);
	return (ft_wstrlen(wstr));
}

int		ft_conv_wc(va_list ap, p_list *lst)
{
	int			i;
	wint_t		wint;
	wchar_t		wbuf;

	i = 0;
	wint = 0;
	if (lst->conv == 'C')
		wint = va_arg(ap, wint_t);
	wbuf = wint;
	write(1, &wbuf, 4);
	return (1);
}
