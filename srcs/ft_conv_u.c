/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:53:41 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:22:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_u(va_list ap, p_list *lst)
{
	int		i;
	int		u;

	i = 0;
	u = 0;
	if (lst->conv == 'u' || lst->conv == 'U')
		u = va_arg(ap, unsigned int);
	ft_putlong(u);
	return (ft_nblen(u));
}
