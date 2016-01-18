/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:35:15 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/18 19:35:20 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_flag(char *tag)
{
	char	*ret;
	int		i;

	ret = NULL;
	while (tag[i] == '#' || tag[i] == '-' || tag[i] == '0'|| tag[i] == '+'
			|| tag[0] == ' ')
		i++;
	if (i == 0)
		return (NULL);
	ft_strsub(ret, 0, i);
	return (ret)
}

int		ft_get_width(char *tag)
{
	char	*str;
	int		ret;
	int		i;

	str = ft_strnew(20);
	ret = 0;
	i = 0;
	if (tag[i] != '.')
	{
		while (ft_isdigit(tag[i]))
		{
				str = tag[i];
				i++;
		}
	}
	else
		return (-1);
	ret = ft_atoi(str);
	free(str);
	return (ret);
}

int		ft_get_prec(char *tag)
{
	char	*str;
	int		ret;
	int		i;

	str = ft_strnew(20);
	ret = 0;
	i = 0;
	if (tag[i] == '.')
		*tag++;
	else
		return (-1);
	while (ft_isdigit(tag[i]))
	{
		str = tag[i];
		i++;
	}
	if (i == 0)
		return (0);
	ret = ft_atoi(str);
	free(str);
	return (ret);
}

char	*ft_get_modif(char *tag)
{
	char	*str;
	int		i;

	str = ft_strnew(3);
	i = 0;
	while (i < 2 && (tag[i] == 'h' || tag[i] == 'l' || tag[i] == 'j'
				|| tag[i] == 'z'))
	{
		str[i] = tag[i];
		i++;
	}
	return (str);
}

char	ft_get_conv(char *tag)
{
	if (format[0] == 's' || format[0] == 'S' || format[0] == 'p'
			|| format[0] == 'd' || format[0] == 'D' || format[0] == 'i'
			|| format[0] == 'o' || format[0] == 'O' || format[0] == 'u'
			|| format[0] == 'U' || format[0] == 'x' || format[0] == 'X'
			|| format[0] == 'c' || format[0] == 'C' || format[0] == '%')
		return (format[0]);
	else
		return ('\0');
}
