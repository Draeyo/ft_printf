/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 16:20:17 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_itoo(unsigned int nb)
{
	unsigned int	ret;
	int				mult;

	ret = 0;
	mult = 1;
	while (nb)
	{
		ret += nb % 8 * mult;
		mult *= 10;
		nb /= 8;
	}
	return (ret);
}

unsigned long long		ft_lltoo(unsigned long long nb)
{
	unsigned long long 	ret;
	int					mult;

	ret = 0;
	mult = 1;
	while (nb)
	{
		ret += nb % 8 * mult;
		mult *= 10;
		nb /= 8;
	}
	return (ret);
}
