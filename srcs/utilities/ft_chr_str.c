/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chr_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/20 09:58:30 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <stdio.h>

void	ft_putchar_count_fd(char c, int fd, int *in_len)
{
	ft_putchar_fd(c, fd);
	*in_len += 1;
}

void	ft_pad(int width, int precision, int pad, int *in_len)
{
	while (width > precision)
	{
		ft_putchar_count_fd(pad, 1, in_len);
		width--;
	}
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *in_len)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar_count_fd(str[i], fd, in_len);
		i++;
	}
}
