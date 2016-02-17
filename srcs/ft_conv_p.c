/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:19:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 16:58:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_get_beginning(char *str)
{
	str = ft_strnew(6);
	str[0] = '0';
	str[1] = 'x';
	str[2] = '7';
	str[3] = 'f';
	str[4] = 'f';
	str[5] = 'f';
	return (str);
}

int					ft_conv_p(va_list ap, p_list *lst)
{
	void			*p;
	char			*str;
	unsigned int	stock;
	char			*pnt;

	p = 0;
	stock = 0;
	pnt = NULL;
	pnt = ft_get_beginning(pnt);
	str = ft_strnew(40);
	if (lst->conv == 'p')
		p = va_arg(ap, void*);
	stock = (unsigned int)p;
	str = ft_itohex(stock);
	ft_strcat(pnt, str);
	free(str);
	ft_putstr(ft_padding(ft_width(lst, ft_strlen(pnt)),
				ft_prec(lst, ft_strlen(pnt)), pnt, lst));
	free(pnt);
	return (ft_strlen(pnt));
}
