/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:10:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strnew_digit(int nb, int fill)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (nb + 1));
	while (nb--)
	{
		str[i] = fill;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_width(p_list *lst, int len)
{
	char	*width;
	int		i;

	if (lst->width <= 0)
		return (NULL);
	i = 0;
	if (lst->prec < len)
		lst->prec = 0;
	if (lst->prec > lst->width)
		return (NULL);
	if (lst->prec)
		lst->width -= lst->prec;
	else if ((lst->width -= len) <= 0)
		return (NULL);
	if (!(width = ft_strnew_digit(lst->width, ' ')))
		return (NULL);
	return (width);
}

char			*ft_prec(p_list *lst, int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (lst->conv == 'p' || lst->conv == 'c')
		return (NULL);
	else if (lst->conv == 's')
		return (ft_strnew_digit(lst->prec, ' '));
	if ((lst->prec -= len) <= 0)
		return (NULL);
	prec = ft_strnew_digit(lst->prec, '0');
	return (prec);
}

char			*ft_padding(char *width, char *prec, char *elem, p_list *lst)
{
	char	*padding;

	padding = NULL;
	if (prec && lst->conv != 's')
		padding = ft_strjoin(prec, elem);
	else if (lst->prec && lst->conv == 's')
		padding = ft_strcut(elem, lst->prec);
	else
		padding = ft_strnewcpy(elem);
	if (width && !ft_strchr(lst->tag, '-'))
		padding = ft_strjoin(width, padding);
	else if (width && ft_strchr(lst->tag, '-'))
		padding = ft_strjoin(padding, width);
	return (padding);
}
