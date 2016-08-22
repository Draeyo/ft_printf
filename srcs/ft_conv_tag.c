/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:14:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/22 14:22:24 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			lst_init(t_print *lst)
{
	lst->tag = NULL;
	lst->flag = NULL;
	lst->width = 0;
	lst->prec = 0;
	lst->modif = NULL;
	lst->conv = '\0';
	lst->len = 0;
	lst->neg = 0;
	lst->hex = NULL;
	lst->zeroflag = ' ';
	lst->zeroprec = 0;
}

int				ft_conv_tag(const char *format, t_print *lst)
{
	int		k;
	int		ret;

	k = 0;
	ret = 0;
	lst_init(lst);
	if (!(lst->tag = ft_get_tag(&format[1], ft_get_last(&format[1], 0))))
		return (1);
	if (ft_get_flag(lst->tag + k, lst) < 0)
		return (ft_tag_error(lst, format));
	else
		k += (int)ft_strlen(lst->flag);
	ret = ft_get_width(lst->tag + k, lst);
	// faire les autres sur le meme principe
	if (ret < -1)
		return (ft_tag_error(lst, format));
	else if (ret > -1)
		k += ft_nblen(lst->width);
	ret = ft_get_prec(lst->tag + k, lst);
//	if (ft_get_prec(lst->tag + k, lst) == -3)
	if (ret == -3)
		k += 2;
//	else if (ft_get_prec(lst->tag + k, lst) < -1)
	else if (ret < -1)
		return (ft_tag_error(lst, format));
	else if (ret == -1)
		k++;
	else if (ret > 0)
		k += ft_nblen(lst->prec) + 1;
	if (ft_get_modif(lst->tag + k, lst) < 0)
		return (ft_tag_error(lst, format));
	else if (lst->modif)
		k += ft_strlen(lst->modif);
	if (ft_get_conv(lst->tag + k, lst) < 0)
		return (ft_tag_error(lst, format));
	else
		k++;
	lst->len = ft_strlen(lst->tag) + 1;
	return (lst->len);
}
