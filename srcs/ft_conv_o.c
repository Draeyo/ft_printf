/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:21:13 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_o(va_list ap, p_list *lst)
{
	int				i;
	unsigned int	o;

	i = 0;
	o = 0;
	if (lst->conv == 'o' || lst->conv == 'O')
		o = va_arg(ap, unsigned int);
	ft_putnbo(o);
	return (ft_nblen(o));
}
