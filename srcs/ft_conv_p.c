/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:19:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 12:22:36 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_get_beginning(char *str)
{
	str = ft_strnew(40);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '7';
	str[3] = 'f';
	str[4] = 'f';
	str[5] = 'f';
	return (str);
}

int					ft_conv_p(va_list ap, t_print *lst)
{
	void			*p;
	char			*str;
	unsigned int	stock;
	char			*pnt;

	pnt = NULL;
	p = 0;
	stock = 0;
	pnt = ft_get_beginning(pnt);
	str = ft_strnew(40);
	if (lst->conv == 'p')
		p = va_arg(ap, void*);
	stock = (unsigned int)p;
	str = ft_itohex(stock);
	pnt = ft_strcat(pnt, str);
	free(str);
	free(pnt);
	if (stock == 0x0)
		return (ft_padding_str(lst, "0x0"));
	return (ft_padding_str(lst, pnt));
}
