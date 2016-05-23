/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_lltoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:25:18 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 12:18:14 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	calc_div(int len)
{
	long long	div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char						*ft_s_lltoa(long long nb)
{
	long long		div;
	char					*ret;
	unsigned int			len;
	int						i;

	i = 0;
	len = ft_llnblen(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
	if (nb == 0)
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
