/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:31 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/29 15:33:04 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_short_pwchar(wchar_t c, int fd)
{
	if (c == 0)
		return (write(fd, "\0", 1));
	return (0);
}

int				ft_putwchar_fd(wchar_t c, int fd)
{
	int		ret;

	ret = ft_short_pwchar(c, fd);
	if (c <= 0x7F)
		ret += ft_putchar_fd(c, fd);
	else if (c <= 0x7FF)
	{
		ret += ft_putchar_fd((c >> 6) + 0xC0, fd);
		ret += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0xFFFF)
	{
		ret += ft_putchar_fd((c >> 12) + 0xE0, fd);
		ret += ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ret += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	else if (c <= 0x10FFFF)
	{
		ret += ft_putchar_fd((c >> 18) + 0xF0, fd);
		ret += ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd);
		ret += ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd);
		ret += ft_putchar_fd((c & 0x3F) + 0x80, fd);
	}
	return (ret);
}

int				ft_putwstr_fd(wchar_t *wstr, int fd)
{
	int		ret;

	ret = 0;
	while (*wstr)
		ret += ft_putwchar_fd(*wstr++, fd);
	return (ret);
}
