/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:27:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 13:12:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(va_list ap, p_list *lst)
{
	int		ret;
	char	*s;

	s = NULL;
	ret = 0;
	if (lst->conv == 's')
	{
		s = va_arg(ap, char*);
		ret = ft_padding_str(lst, s);
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l"))
			|| lst->conv == 'S')
		return (ft_conv_ws(ap, lst));
	return (ret);
}
