/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:15:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/19 16:04:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tag_error(t_print *lst, const char *format)
{
	int		i;

	i = 0;
	lst->conv = '0';
	lst->tag = NULL;
	ft_putendl_fd("Error", 2);
	while (format[i] != ' ')
		i++;
	return (++i);
}
