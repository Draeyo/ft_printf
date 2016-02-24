/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_ltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:16:09 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/24 17:36:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_lnblen(long nb)
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

static int		calc_len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
		return ((len = ft_lnblen(nb) - 1));
	else
		return ((len = ft_lnblen(nb)));
}

static int		calc_div(int len)
{
	int		div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char			*ft_s_ltoa(long nb)
{
	int		div;
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = calc_len(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
	if (nb < 0)
	{
		ret[i] = '-';
		nb *= -1;
		i++;
	}
	else if (nb == 0)
		return ("0");
	while (len-- && div)
	{
		ret[i] = ((nb / div) + 48);
		nb -= ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (ret);
}
