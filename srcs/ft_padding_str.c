/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:26:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 15:29:16 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flags(t_print *lst)
{
	if (FLAG && !NEG && ft_strchr(FLAG, '+') && ft_plus(lst))
		return (ft_putstr("+"));
	else if (FLAG && !NEG && ft_strchr(FLAG, ' ') && ft_plus(lst))
		return (ft_putstr(" "));
	return (0);
}

static char		*ft_diese_o(t_print *lst, char *str)
{
	if ((CONV == 'O' || CONV == 'o') && ft_strchr(FLAG, '#'))
		str = ft_strjoin("0", str);
	return (str);
}

static int		ft_diese_x(t_print *lst, char *str)
{
	if (ft_ishex(lst))
	{
		if (!ft_strstr(str, "0") && ft_strchr(FLAG, '#')
				&& (!ft_strchr(FLAG, '0') || (ft_strchr(FLAG, '0')
						&& ft_strchr(FLAG, '-'))))
		{
			PREC -= 2;
			return (ft_putstr(HEX));
		}
	}
	return (0);
}

static int		ft_short_pstr(t_print *lst, char *str, int ret, int len)
{
	if (ft_strchr(FLAG, '0'))
		ret += ft_flags(lst);
	if (!ft_strchr(FLAG, '-'))
		ret += ft_putstr(ft_width(lst, len));
	if (!ft_strchr(FLAG, '0'))
		ret += ft_flags(lst);
	ret += ft_diese_x(lst, str);
	if (CONV != 's' && CONV != 'S')
		ret += ft_putstr(ft_prec(lst, len));
	if (PREC < 0)
		PREC = 0;
	if (CONV == 'X')
		str = ft_xupper(str);
	if (CONV == 's' || CONV == 'S')
		ret += write(1, str, (PREC < len && PREC > 0) ? PREC : len);
	else if (CONV == 'c')
		ret += ft_putchar(*str);
	else
	{
		if ((!PREC && !ft_strchr(FLAG, '0')) && ft_plus(lst) && NEG == 1)
			ret += ft_putchar('-');
		ret += ft_putstr(str);
	}
	return (ret);
}

int				ft_padding_str(t_print *lst, char *str)
{
	int		ret;
	int		len;

	ret = 0;
	if (ft_zeroflag(lst) && ft_strchr(FLAG, '0') && !ft_strchr(FLAG, '-'))
		ZEROF = '0';
	if (CONV == 'o' || CONV == 'O')
		str = ft_diese_o(lst, str);
	len = (int)ft_strlen(str);
	if (CONV == 'c')
		len = 1;
	if ((CONV == 'x' || CONV == 'X') && ft_strchr(FLAG, '#'))
		len += 2;
	else if (NEG == 1)
	{
		len++;
		PREC++;
	}
	ret += ft_short_pstr(lst, str, ret, len);
	if (ft_strchr(FLAG, '-'))
		ret += ft_putstr(ft_width(lst, len));
	return (ret);
}
