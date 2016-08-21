/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:15:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/21 14:07:02 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tag_error(t_print *lst, const char *format)
{
	int		i;

	i = 0;
	lst->conv = '0';
	lst->tag = NULL;
	ft_putendl_fd(lst->tag, 2);
	while (format[i] != ' ')
		i++;
	return (++i);
}

int		ft_zeroflag(t_print *lst)
{
	char	c;

	c = lst->conv;
	if (((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'D' || c == 'O' || c == 'U') && lst->prec > 0) || lst->conv == 's')
		return (0);
	return (1);
}
