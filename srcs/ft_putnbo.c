/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:37:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 15:07:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbo(unsigned int nb)
{
	char	*str;
	char	*pnt;
	int		i;

	str = ft_strnew(20);
	pnt = str;
	i = 0;
	while (nb)
	{
		str[i] = (nb % 8) + 48;
		nb /= 8;
		i++;
	}
	str = ft_strrev(str);
	ft_putstr(str);
	free(pnt);
}
