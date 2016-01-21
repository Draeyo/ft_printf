/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:56:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/21 17:29:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (nb < 0)
	{
		n *= -1;
		i++;
	}
	else if (nb == 0)
		return (1);
	n = (unsigned int)nb;
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
