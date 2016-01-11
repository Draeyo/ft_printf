/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:19:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 19:49:14 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_p(const char *format, va_list ap)
{
	int				i;	
	void*			p;
	char			*str;
	unsigned int	stock;
	char			*pnt;

	i = 0;
	p = 0;
	stock = 0;
	pnt = ft_strnew(50);
	str = ft_strnew(40);
	pnt[0] = '0';
	pnt[1] = 'x';
	pnt[2] = '7';
	pnt[3] = pnt[4] = pnt[5] = 'f';
	if (format[i] == 'p')
		p = va_arg(ap, void*);
	stock = (unsigned int)p;
	str = ft_itohex(stock);
	ft_strcat(pnt, str);
	ft_putstr(pnt);
	return (ft_strlen(pnt));
}
