/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/24 17:10:24 by vlistrat         ###   ########.fr       */
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

char			*ft_lltoo(unsigned long long nb)
{
	int		mult;
	char	*ret;
	char	*pnt;

	ret = ft_strnew(200);
	pnt = ret;
	mult = 1;
	while (nb)
	{
		ret = ft_strjoin(ret, ft_s_itoa((nb % 8 * mult)));
		nb /= 8;
	}
	ret = ft_strrev(ret);
	free(pnt);
	return (ret);
}

char			*ft_sttoo(size_t nb)
{
	int		mult;
	char	*ret;
	char	*pnt;

	ret = ft_strnew(200);
	pnt = ret;
	mult = 1;
	while (nb)
	{
		ret = ft_strjoin(ret, ft_s_itoa((nb % 8 * mult)));
		nb /= 8;
	}
	ret = ft_strrev(ret);
	free(pnt);
	return (ret);
}
