/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_functions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/12 17:24:28 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

void	ft_padzero(int width, int precision, int pad, int *input_len)
{
	while (width > precision)
	{
		*input_len += 1;
		ft_putchar_fd(pad, 1);
		width--;
	}
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *input_len)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0' && i < n)
	{
		input_len++;
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
