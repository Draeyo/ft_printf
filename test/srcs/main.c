/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:35:36 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/11 20:16:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char		str[] = "HELLO";
	int			nb = 128;
	int			li = 4294967295;
	wchar_t		wstr[] = L"HELLO";
	int			i;

	i = 0;
	ft_printf("%d || %% || %s || %D || %d || %x || %X || %c || %o || %p\n", nb, str, li, li, li, li, 'r', nb, &nb);
	printf("%d || %% || %s || %D || %d || %x || %X || %c || %o || %p\n", nb, str, li, li, li, li, 'r', nb, &nb);
	printf("\n");
	ft_printf("%S || %C\n", wstr, 'H');
	printf("%S || %C\n", wstr, 'H');
	return (0);
}
