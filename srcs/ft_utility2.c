/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 13:19:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/29 15:06:44 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(t_print *lst, char *str, int ret)
{
	if (CONV == 's' || (CONV == 'S' && !WSTR))
		ret += write(1, str, (PREC < LEN && PREC > 0) ? PREC : LEN);
	else if (CONV == 'c' && *str == '\0')
		ret += write(1, "\0", 1);
	else if (!MODIF && CONV == 'c')
		ret += ft_putchar(*str);
	else if (CONV == 'S' && WSTR)
		ret += ft_putwstr_fd(WSTR, 1);
	else if (CONV == 'C' || (MODIF && ft_strstr(MODIF, "l") && CONV == 'C'))
		ret += ft_putwchar_fd(WC, 1);
	else
	{
		if (ft_spstr_min(lst))
			ret += ft_putchar('-');
		ret += ft_putstr(str);
	}
	return (ret);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int		ret;

	ret = 0;
	while (*wstr++)
	{
		if (*wstr <= 0x7f)
			ret++;
		else if (*wstr <= 0x7ff)
			ret += 2;
		else if (*wstr <= 0xffff)
			ret += 3;
		else if (*wstr <= 0x10ffff)
			ret += 4;
	}
	return (ret);
}
