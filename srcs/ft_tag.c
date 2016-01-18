/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:28:09 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:12:35 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tag(va_list ap, p_list *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (lst->conv == '%')
		j = ft_noconv(p_list *lst);
	else if (lst->conv == 's')
		j = ft_conv_s(ap, p_list *lst);
	else if (lst->conv == 'd' || lst->conv == 'i' || lst->conv == 'D')
		j = ft_conv_d(ap, p_list *lst);
	else if (lst->conv == 'x' || lst->conv == 'X')
		j = ft_conv_x(ap, p_list *lst);
	else if (lst->conv == 'c')
		j = ft_conv_c(ap, p_list *lst);
	else if (lst->conv == 'o' || lst->conv == 'O')
		j = ft_conv_o(ap, p_list *lst);
	else if (lst->conv == 'p')
		j = ft_conv_p(ap, p_list *lst);
	else if (lst->conv == 'S')
		j = ft_conv_ws(ap, p_list *lst);
	else if (lst->conv == 'C')
		j = ft_conv_wc(ap, p_list *lst);
	else if (lst->conv == 'u' || lst->conv == 'U')
		j = ft_conv_u(ap, p_list *lst);
	return (j);
}
