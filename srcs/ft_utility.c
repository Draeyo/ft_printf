/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:15:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/05/03 12:20:58 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isneg(char *str, p_list *lst)
{
	if (str[0] == '-' && (lst->conv == 'd' || lst->conv == 'i'))
		return (1);
	return (0);
}

char	*ft_strnegjoin(char *prec, char *elem)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strjoin(prec, elem);
	while(ret[i] != '-')
		i++;
	ret[i] = '0';
	ret = ft_strjoin("-", ret);
	return (ret);
}

char	*ft_zerowidth(char *width, char *elem)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strjoin(width, elem);
	while (ret[i] != '-')
		i++;
	ret[i] = '0';
	ret[0] = '-';
	return (ret);
}

int		ft_tag_error(p_list *lst, const char *format)
{
	int		i;

	i = 0;
	lst->conv = '0';
	lst->tag = NULL;
	while (format[i] != ' ')
		i++;
	return (++i);
}

int		ft_next_arg(va_list ap)
{
	int		bin;

	bin = va_arg(ap, int);
	bin = 0;
	return (0);
}
