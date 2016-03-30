/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:40:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/20 16:33:09 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(va_list ap, p_list *lst)
{
	char	c;
	char	*cstr = NULL;
	char	*str = NULL;

	c = 0;
	if (lst->conv == 'c')
	{
		c = va_arg(ap, int);
		cstr = ft_strnew_digit(1, c);
		ft_putstr((str = ft_padding(ft_width(lst, 1), ft_prec(lst, 1), cstr, lst)));
		free(cstr);
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l"))
			|| lst->conv == 'C')
		return (ft_conv_wc(ap, lst));
	if (!c)
		return (1);
	return (ft_strlen(str));
}
