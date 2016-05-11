/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:41:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/03 12:31:28 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noconv(p_list *lst)
{
	char	*str = NULL;

	if (lst->conv == '%')
		ft_putstr((str = ft_padding(ft_width(lst, 1), ft_prec(lst, 1), "%", lst)));
	return (ft_strlen(str));
}
