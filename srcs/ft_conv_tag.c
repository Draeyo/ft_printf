/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:14:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 20:07:37 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		lst_init(p_list *lst)
{
	lst->tag = NULL;
	lst->flag = NULL;
	lst->width = 0;
	lst->prec = 0;
	lst->modif = NULL;
	lst->conv = '\0';
	lst->len = 0;
}

int				ft_conv_tag(const char *format, p_list *lst)
{
	int		k;

	k = 0;
	lst_init(lst);
	lst->tag = ft_get_tag(&format[1], ft_get_last(format, i));
	if ((lst->flag = ft_get_flag(&tag[k])) != NULL)
		k += ft_strlen(lst->flag);
	if ((lst->width = ft_get_width(&tag[k])) >= 0)
		k += ft_nblen(lst->tag);
	if ((lst->prec = ft_get_prec(&tag[k])) >= 0)
		(lst->prec == 0 ? k++ : k += ft_nblen(lst->prec));
	if ((lst->modif = ft_get_modif(&tag[k])) != NULL)
		k += ft_strlen(lst->prec);
	if ((lst->conv = ft_get_conv(&tag[k])) != '\0')
		k++;
	lst->len = ft_strlen(lst->tag) + 1;
	return (lst->len);
}
