/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_uitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:08:57 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:17:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		calc_div(int len)
{
	int		div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char			*ft_s_uitoa(unsigned int nb)
{
	int		div;
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_unblen(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
	if (nb == 0)
		return ("0");
	while (len--)
	{
		ret[i] = ((nb / div) + 48);
		nb -= ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (ret);
}
