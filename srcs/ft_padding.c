/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 14:33:27 by vlistrat         ###   ########.fr       */
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

char		*ft_width(t_print *lst, int len)
{
	char	*width;
	int		i;

	if ((ft_strchr(FLAG, '+') || ft_strchr(FLAG, ' ')) && WIDTH > len
			&& ft_plus(lst) && NEG == 0)
		WIDTH--;
	i = 0;
	if (PREC < len && !ft_is_c(lst) && !ft_strchr(FLAG, '-'))
		PREC = 0;
	if (PREC > WIDTH)
		return (NULL);
	if (PREC && len > 0 && (!ft_strchr(FLAG, '-') || CONV == 's'))
		WIDTH -= PREC;
	else if ((WIDTH -= len) <= 0)
		return (NULL);
	if (ft_strchr(FLAG, '-') && CONV != 's')
		WIDTH -= PREC;
	if (!(width = ft_strnew_digit(WIDTH, ZEROF)))
		return (NULL);
	if (ft_ishex(lst) && ft_strchr(FLAG, '0') && !ft_strchr(FLAG, '-'))
	{
		PREC -= 2;
		return (ft_strjoin(HEX, ft_strnew_digit(WIDTH, ZEROF)));
	}
	return (width);
}

char		*ft_prec(t_print *lst, int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (CONV == 'p' || CONV == 'c' || CONV == '%')
		return (NULL);
	else if (CONV == 's')
		return (ft_strnew_digit(PREC, ' '));
	if ((PREC -= len) <= 0)
		return (NULL);
	prec = ft_strnew_digit(PREC, '0');
	return (prec);
}
