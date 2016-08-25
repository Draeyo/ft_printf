/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:19:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/25 14:05:09 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_conv_p(va_list ap, t_print *lst)
{
	unsigned long	p;

	p = va_arg(ap, unsigned long);
	HEX = "0x";
	if (!ZEROP)
		STR = ft_itohex(p);
	return (ft_padding_str(lst, STR));
}
