/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 14:56:09 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 16:48:48 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

int     main(void)
{
    char *str1 = "|%04p|\n";
	ft_printf(str1, 5);
	printf(str1, 5);
    char *str2 = "|%040p|\n";
	ft_printf(str2, 5);
	printf(str2, 5);
    // char *str3 = "|%18.0ld|\n";
	// ft_printf(str3, 2000);
	// printf(str3, 2000);
    // char *str4 = "|%1.0ld|\n";
	// ft_printf(str4, 2000);
	// printf(str4, 2000);
    // char *str5 = "|%01.0ld|\n";
	// ft_printf(str5, 2000);
	// printf(str5, 2000);
    // char *str6 = "|%018.0ld|\n";
	// ft_printf(str6, 2000);
	// printf(str6, 2000);
    // char *str7 = "|%10.0ld|\n";
	// ft_printf(str7, 2000);
	// printf(str7, 2000);
    // char *str8 = "|%010.0ld|\n";
	// ft_printf(str8, 2000);
	// printf(str8, 2000);
    return (0);
}
