/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:35:15 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 15:02:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(char *tag, t_print *lst)
{
	int		i;

	i = 0;
	while (tag[i] && (tag[i] == '#' || tag[i] == '-' || tag[i] == '0'
				|| tag[i] == '+' || tag[i] == ' '))
		i++;
	if (i == 0 || i == (int)ft_strlen(tag))
	{
		lst->flag = "\0";
		return (0);
	}
	else if (!ft_after_flag(tag[i]))
		return (-1);
	FLAG = ft_strsub(tag, 0, i);
	return (1);
}

int		ft_get_width(char *tag, t_print *lst)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(20);
	if (tag[i] != '.' && ft_isdigit(tag[i]))
	{
		while (ft_isdigit(tag[i]))
		{
			str[i] = tag[i];
			i++;
		}
		if (i == 0 || i == (int)ft_strlen(tag))
			return (0);
		else if (!ft_after_width(tag[i]))
			return (-2);
		WIDTH = ft_s_atoi(str);
		free(str);
		return (1);
	}
	else
		return (-1);
}

int		ft_get_prec(char *tag, t_print *lst)
{
	char	*str;
	int		i;
	int		temp;

	str = ft_strnew(20);
	i = 0;
	temp = 0;
	if ((temp = ft_zprec(lst, tag, i)) <= 0)
		return (temp);
	else
		tag = &tag[1];
	if (!ft_isdigit(*tag))
		return (-1);
	while (ft_isdigit(tag[i]))
	{
		str[i] = tag[i];
		i++;
	}
	if (!ft_after_prec(tag[i]))
		return (-2);
	PREC = ft_s_atoi(str);
	free(str);
	return (1);
}

int		ft_get_modif(char *tag, t_print *lst)
{
	char	*str;
	int		i;

	str = ft_strnew(3);
	i = 0;
	if (!ft_ismod(tag[i]))
		return (0);
	while (i < 2 && ft_ismod(tag[i]))
	{
		str[i] = tag[i];
		i++;
	}
	if (i == 0)
		return (0);
	else if (!ft_isconv(tag[i]))
		return (-1);
	MODIF = ft_strdup(str);
	free(str);
	return (1);
}

int		ft_get_conv(char *tag, t_print *lst)
{
	if (ft_isconv(tag[0]))
	{
		CONV = tag[0];
		return (1);
	}
	else
		return (-1);
}
