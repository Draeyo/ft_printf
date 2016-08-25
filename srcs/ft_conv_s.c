/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:27:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/25 16:21:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(va_list ap, t_print *lst)
{
	int		ret;
	char	*s;

	s = NULL;
	ret = 0;
	if (lst->conv == 's')
	{
		s = va_arg(ap, char*);
		if (s == NULL)
			ret = ft_padding_str(lst, "(null)");
		else if (ZEROP)
			ret = ft_padding_str(lst, "");
		else
			ret = ft_padding_str(lst, s);
	}
	else if ((lst->modif != NULL && ft_strstr(lst->modif, "l"))
			|| lst->conv == 'S')
		return (ft_conv_ws(ap, lst));
	return (ret);
}
