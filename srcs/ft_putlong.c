/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:04:35 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 19:10:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
