/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/19 16:19:44 by vlistrat         ###   ########.fr       */
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

char			*ft_width(t_print *lst, int len)
{
	char	*width;
	int		i;
	int		flag;

	flag = ' ';
	if (lst->conv == 'c')
		len = 1;
	if (ft_ishex(lst) && !ft_strchr(lst->flag, '0'))
		lst->prec -= 2;
	if (lst->conv != 's' && !lst->prec && ft_strchr(lst->flag, '0') && !ft_strchr(lst->flag, '-'))
			flag = '0';
	if (lst->width <= 0)
		return (NULL);
	if ((ft_strchr(lst->flag, '+') || ft_strchr(lst->flag, ' ')) && lst->width > len
			&& ft_plus(lst) && lst->neg == 0)
		lst->width--;
	i = 0;
	if (lst->prec < len && !ft_is_c(lst))
		lst->prec = 0;
	if (lst->prec > lst->width)
		return (NULL);
	if (lst->prec && len > 0)
		lst->width -= lst->prec;
	else if ((lst->width -= len) <= 0)
		return (NULL);
	if (!(width = ft_strnew_digit(lst->width, flag)))
		return (NULL);
	if (ft_ishex(lst) && ft_strchr(lst->flag, '0') && !ft_strchr(lst->flag, '-'))
	{
		lst->prec -= 2;
		return (ft_strjoin(lst->hex, ft_strnew_digit(lst->width, flag)));
	}
	return (width);
}

char			*ft_prec(t_print *lst, int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (lst->conv == 'p' || lst->conv == 'c' || lst->conv == '%')
		return (NULL);
	else if (lst->conv == 's')
		return (ft_strnew_digit(lst->prec, ' '));
	if ((lst->prec -= len) <= 0)
		return (NULL);
	prec = ft_strnew_digit(lst->prec, '0');
	return (prec);
}
