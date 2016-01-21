/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:04:35 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 16:35:10 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(unsigned long long nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_put_unsigned_int(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
