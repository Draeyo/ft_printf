/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:35:36 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/20 19:29:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char		str[] = "HELLO";
	int			nb = 128;
	int			li = 4294967295;
	wchar_t		wstr[] = L"HELLO";
	unsigned long long	a = 9223372036854775807;
	uintmax_t	uintmax = UINTMAX_MAX;
	char		c = 'C';

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
	ft_printf("hhd : %hhd || %hhd\n", c, (char)'A');
	printf("hhd : %hhd || %hhd\n", c, (char)'A');
	ft_printf("--------------------\n");
	ft_printf("hd : %hd || %hd\n", (short)32768, (short)-32769);
	printf("hd : %hd || %hd\n", (short)32768, (short)-32769);
	ft_printf("--------------------\n");
	printf("UINT_MAX : %D\n", UINT_MAX);
	printf("LONG_MAX : %ld\n", LONG_MAX);
	printf("LONG_MAX : %llU || %lu\n", a + 1, sizeof(a));
	printf("ULONG_MAX : %lu\n", ULONG_MAX);
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("ULLONG_MAX : %llu\n", ULLONG_MAX);
	printf("uintmax_t : %ju", uintmax);
	return (0);
}
