/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:40:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 17:37:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(va_list ap, t_print *lst)
{
	char	c;

	c = 0;
	if (lst->conv == 'c')
	{
		c = va_arg(ap, int);
		if (c)
			return (ft_padding_str(lst, &c));
		else
			return ((lst->width > 1) ? lst->width : 1);
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l"))
			|| lst->conv == 'C')
		return (ft_conv_wc(ap, lst));
	return (0);
}
