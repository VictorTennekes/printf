/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utilities.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/14 14:56:16 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar_count_fd(char c, int fd, int *input_len)
{
	ft_putchar_fd(c, fd);
	input_len += 1;
}

void	ft_padzero(int width, int precision, int pad, int *input_len)
{
	while (width > precision)
	{
		ft_putchar_count_fd(pad, 1, input_len);
		width--;
	}
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *input_len)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar_count_fd(str[i], fd, input_len);
		i++;
	}
}

void	ft_prep_int(t_conv *conv, int i)
{
	if (i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->size = ft_putint_size(i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
}

int		ft_putint_size(int i, t_conv *conv)
{
	int		tmp;
	int		size;

	tmp = i;
	size = 0;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

void	ft_putint_n_fd(int i, int *input_len)
{
	int		tmp;
	int		pow;

	tmp = i;
	pow = 1;
	while (tmp / 10)
	{
		tmp = tmp / 10;
		pow = pow * 10;
	}
	while (pow)
	{
		ft_putchar_count_fd(((i < 0) ? '0' - i / pow :
							'0' + i / pow), 1, input_len);
		i = i % pow;
		pow = pow / 10;
	}
}
