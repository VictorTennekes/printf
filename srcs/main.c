/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:23:11 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/18 12:27:25 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("result me:\n");
	ft_printf("%llu\n\n", 18446744073709551615ull);
	printf("result comp:\n");
	printf("%llu\n", 18446744073709551615ull);
	return (0);
}
