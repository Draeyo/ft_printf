/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:40:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 18:07:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(va_list ap, p_list *lst)
{
	int		c;

	c = 0;
	if (lst->conv == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l")) || lst->conv == 'C')
		return (ft_conv_wc(ap, lst));
	return (1);
}
