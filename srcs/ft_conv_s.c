/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:27:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:06:56 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(va_list ap, p_list *lst)
{
	char	*s;

	s = NULL;
	if (lst->conv == 's')
	{
		s = va_arg(ap, char*);
		ft_putstr(ft_padding(ft_width(lst, ft_strlen(s)),
					ft_prec(lst, ft_strlen(s)), s, lst));
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l"))
			|| lst->conv == 'S')
		return (ft_conv_ws(ap, lst));
	return (ft_strlen(s));
}
