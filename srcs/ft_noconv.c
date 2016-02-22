/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:41:38 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/22 15:38:41 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noconv(p_list *lst)
{
	char	*str = NULL;
	char	*noconv;

	noconv = ft_strnew_digit(1, '%');
	if (lst->conv == '%')
		ft_putstr((str = ft_padding(ft_width(lst, 1), ft_prec(lst, 1), noconv, lst)));
	free(noconv);
	return (ft_strlen(str));
}
