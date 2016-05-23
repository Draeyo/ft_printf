/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:56:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 12:30:15 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(intmax_t nb)
{
	int						i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_unblen(unsigned int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_llnblen(long long nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
