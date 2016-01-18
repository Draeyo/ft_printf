/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:13:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_d(va_list ap, p_list *lst)
{
	int				i;
	int				d;
	unsigned int	ud;

	i = 0;
	d = 0;
	if (lst->conv == 'd' || format[i] == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		return (ft_nblen(d));
	}
	else if (lst->conv == 'D')
	{
		ud = va_arg(ap, unsigned int);
		ft_putlong(ud);
		return (ft_nblen(ud));
	}
	return (0);
}
