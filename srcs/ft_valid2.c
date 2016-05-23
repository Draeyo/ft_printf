/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:21:53 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 14:07:07 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_after_prec(int c)
{
	if (!ft_ismod(c) && !ft_isconv(c))
		return (0);
	return (1);
}

int		ft_plus(p_list *lst)
{
	if (lst->conv == 'd' || lst->conv == 'D' || lst->conv == 'i')
		return (1);
	return (0);
}
