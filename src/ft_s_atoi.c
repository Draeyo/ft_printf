/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:11:18 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 17:28:39 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_atoi(char *str)
{
	int		ret;
	int		mult;
	int		i;

	i = ft_strlen(str);
	mult = 1;
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret += ((str[i] - 48) * mult);
		mult *= 10;
		i--;
	}
	if (str[i] == '-')
		ret *= -1;
	return (ret);
}
