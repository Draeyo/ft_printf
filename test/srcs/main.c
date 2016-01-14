/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:35:36 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/13 15:19:24 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char		str[] = "HELLO";
	int			nb = 128;
	int			li = 4294967295;
	wchar_t		wstr[] = L"HELLO";

	ft_printf("--------------------\n");
	ft_printf("%% : %%\n");
	printf("%% : %%\n");
	ft_printf("--------------------\n");
	ft_printf("s : %s\n", str);
	printf("s : %s\n", str);
	ft_printf("--------------------\n");
	ft_printf("S : %S\n", wstr);
	printf("S : %S\n", wstr);
	ft_printf("--------------------\n");
	ft_printf("D : %D || %D\n", li, nb);
	printf("D : %D || %D\n", li, nb);
	ft_printf("--------------------\n");
	ft_printf("d : %d || %d\n", nb, li);
	printf("d : %d || %d\n", nb, li);
	ft_printf("--------------------\n");
	ft_printf("i : %i\n", nb);
	printf("i : %i\n", nb);
	ft_printf("--------------------\n");
	ft_printf("x : %x || %x\n", li, nb);
	printf("x : %x || %x\n", li, nb);
	ft_printf("--------------------\n");
	ft_printf("X : %X || %X\n", li, nb);
	printf("X : %X || %X\n", li, nb);
	ft_printf("--------------------\n");
	ft_printf("c : '%c' || '%c'\n", 'r', 65);
	printf("c : '%c' || '%c'\n", 'r', 65);
	ft_printf("--------------------\n");
	ft_printf("C : %C\n", 'H');
	printf("C : %C\n", 'H');
	ft_printf("--------------------\n");
	ft_printf("o : %o || %o\n", nb, li);
	printf("o : %o || %o\n", nb, li);
	ft_printf("--------------------\n");
	ft_printf("O : %O || %O\n", li, nb);
	printf("O : %O || %O\n", li, nb);
	ft_printf("--------------------\n");
	ft_printf("u : %u || %u || %u\n", li, nb, -2147483647);
	printf("u : %u || %u || %u\n", li, nb, -2147483647);
	ft_printf("--------------------\n");
	ft_printf("U : %U || %U || %U\n", li, nb, -2147483647);
	printf("U : %U || %U || %U\n", li, nb, -2147483647);
	ft_printf("--------------------\n");
	ft_printf("p : %p || %p\n", &nb, &str);
	printf("p : %p || %p\n", &nb, &str);
	ft_printf("--------------------\n");
	return (0);
}
