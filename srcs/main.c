/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:23:11 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 10:58:46 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

int	main(void)
{
	// printf("result me:\n");
	// ft_printf("%llu\n\n", 18446744073709551615ull);
	// printf("result comp:\n");
	// printf("%llu\n", 18446744073709551615ull);
	// return (0);
	// int c;
	// int b;

	// int thing = 86.68;
	// printf("system:\n");
	// printf("geeks for %ngeeks:\t", &c);
	// printf("%d\n", c);
	// printf("mine:\n");
	// ft_printf("geeks for %ngeeks:\t", &b);
	// ft_printf("%d\n", b);
	//tests
	// printf("\n\n\t---<INT>---\n");
	// printf("systemcount: %i\n", printf("number: %i\t", 8));
	// ft_printf("my count: %i\n", ft_printf("number: %i\t", 8));
	// printf("systemcount: %i\n", printf("number: %.6i\t", 8));
	// ft_printf("my count: %i\n", ft_printf("number: %.6i\t", 8));
	// printf("\n\t---<CHAR>---\n");
	// printf("systemcount: %i\n", printf("char: %c\t", 'c'));
	// ft_printf("my count: %i\n", ft_printf("char: %c\t", 'c'));
	// printf("\n\t---<STRING>---\n");
	// printf("systemcount: %i\n", printf("string: %s\t", "string"));
	// ft_printf("my count: %i\n", ft_printf("string: %s\t", "string"));
	// printf("\n\t---<FLOAT>---\n");
	// printf("systemcount: %i\n", printf("string: %f\t", 867555555.6647334373));

	// printf("%i", thing);

	// char *str = "%.0i\n";
    // ft_printf(str, 20);
    // printf(str, 20);
	char *str11 = "|%-101.+.60d|\n";
	ft_printf(str11, 2000);
	printf(str11, 2000);
	char *str123 = "|%.-+100d|\n";
	ft_printf(str123, 2000);
	printf(str123, 2000);
	char *str12 = "|%+.100X|\n";
	ft_printf(str12, 2000);
	printf(str12, 2000);
	char *str = "|%.-100X|\n";
	ft_printf(str, 2000);
	printf(str, 2000);
	char *str1 = "|%7x|\n";
	ft_printf(str1, 33000);
	printf(str1, 33000);
	char *str2 = "|%.0s|\n";
	ft_printf(str2, "Griffin has a tiny dick");
	printf(str2, "Griffin has a tiny dick");
	char *str23 = "|%.03s|\n";
	ft_printf(str23, "Griffin has a tiny dick");
	printf(str23, "Griffin has a tiny dick");\
	return (0);
}
