/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/23 15:36:25 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnew_digit(int nb, int fill)
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
	int		flag;

	flag = ' ';
	if (lst->conv != 's' && !lst->prec && ft_strchr(lst->flag, '0'))
			flag = '0';
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
	if (!(width = ft_strnew_digit(lst->width, flag)))
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
	if ((lst->conv == 'x' || lst->conv == 'X') && ft_strchr(lst->flag, '#'))
		return (ft_strjoin("0x", ft_strnew_digit(lst->prec, '0')));
	prec = ft_strnew_digit(lst->prec, '0');
	return (prec);
}
