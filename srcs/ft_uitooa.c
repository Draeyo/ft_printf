/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitooa.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:37:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/21 14:19:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitooa(uintmax_t nb)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(ft_nblen(nb) * 2);
	if (nb == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	while (nb)
	{
		ret[i] = (nb % 8) + 48;
		nb /= 8;
		i++;
	}
	ret = ft_strrev(ret);
	return (ret);
}
