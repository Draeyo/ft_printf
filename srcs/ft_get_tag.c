/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:42:19 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 15:25:23 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_last(const char *format, int i)
{
	while (format[i])
	{
		if (format[i] == 's' || format[i] == 'S' || format[i] == 'p' 
				|| format[i] == 'd' || format[i] == 'D' || format[i] == 'i' 
				|| format[i] == 'o' || format[i] == 'O' || format[i] == 'u' 
				|| format[i] == 'U' || format[i] == 'x' || format[i] == 'X' 
				|| format[i] == 'c'|| format[i] == 'C')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_tag(const char *format, int last)
{
	char	*str;

	if (last == -1)
		return ("OK");
	str = ft_strsub(format, 0, last);
	return (str);
}
