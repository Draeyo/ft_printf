/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:56:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 19:02:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(int nb)
{
	int		i;
	unsigned int n;

	i = 0;
	n = 0;
	if (nb < 0)
		n *= -1;
	n = (unsigned int)nb;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
