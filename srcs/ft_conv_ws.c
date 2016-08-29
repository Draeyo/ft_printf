/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:58:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/29 09:21:24 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_ws(va_list ap, t_print *lst)
{
	wchar_t		*wstr;

	wstr = (wchar_t*)malloc(sizeof(*wstr) * 50);
	if ((lst->modif == NULL && lst->conv == 'S')
			|| (ft_strstr(lst->modif, "l") && lst->conv == 's'))
		wstr = va_arg(ap, wchar_t*);
	if (wstr)
		ft_putwstr_fd(wstr, 1);
	else
		return (ft_padding_str(lst, "(null)"));
	return (ft_wstrlen(wstr));
}

int		ft_conv_wc(va_list ap, t_print *lst)
{
	wint_t		wint;
	wchar_t		wbuf;

	wint = 0;
	if ((lst->modif == NULL && lst->conv == 'C')
			|| (ft_strstr(lst->modif, "l") && lst->conv == 'c'))
		wint = va_arg(ap, wint_t);
	wbuf = wint;
	ft_putwchar_fd(wbuf, 1);
	return (1);
}
