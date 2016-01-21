/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:58:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 18:01:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_ws(va_list ap, p_list *lst)
{
	wchar_t		*wstr;

	wstr = (wchar_t*)malloc(sizeof(*wstr) * 50);
	if ((lst->modif == NULL && lst->conv == 'S') 
			|| (ft_strstr(lst->modif, "l") && lst->conv == 's'))
		wstr = va_arg(ap, wchar_t*);
	ft_putwstr(wstr);
	return (ft_wstrlen(wstr));
}

int		ft_conv_wc(va_list ap, p_list *lst)
{
	wint_t		wint;
	wchar_t		wbuf;

	wint = 0;
	if ((lst->modif == NULL && lst->conv == 'C') 
			|| (ft_strstr(lst->modif, "l") && lst->conv == 'c'))
		wint = va_arg(ap, wint_t);
	wbuf = wint;
	write(1, &wbuf, 4);
	return (4);
}
