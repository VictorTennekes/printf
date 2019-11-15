/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utilities.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/15 15:59:29 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar_count_fd(char c, int fd, int *in_len)
{
	ft_putchar_fd(c, fd);
	in_len += 1;
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

void	ft_putint_count_fd(int i, int *in_len)
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
							'0' + i / pow), 1, in_len);
		i = i % pow;
		pow = pow / 10;
	}
}

void	ft_prep_un_int(t_conv *conv, unsigned int i)
{
	conv->size = ft_putint_un_size(i, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
}

int		ft_putint_un_size(unsigned int i, t_conv *conv)
{
	unsigned int	tmp;
	int				size;

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

void	ft_putint_un_count_fd(unsigned int i, int *in_len)
{
	unsigned int		tmp;
	unsigned int		pow;

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
							'0' + i / pow), 1, in_len);
		i = i % pow;
		pow = pow / 10;
	}
}

void	ft_prephex_int(t_conv *conv, unsigned int num)
{
	conv->size = ft_puthex_size(num, conv);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
}

int		ft_puthex_size(unsigned int i, t_conv *conv)
{
	unsigned int	tmp;
	int				size;

	tmp = i;
	size = 0;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void	ft_puthex_lower_count_fd(unsigned int num, int *in_len)
{
	unsigned int	tmp;
	unsigned int	pow;
	char			*hex;

	hex = "0123456789abcdef";
	tmp = num;
	pow = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		pow *= 16;
	}
	tmp = num;
	while (pow)
	{
		ft_putchar_count_fd(hex[num / pow], 1, in_len);
		num %= pow;
		pow /= 16;
	}
}

void	ft_puthex_upper_count_fd(unsigned int num, int *in_len)
{
	unsigned int	tmp;
	unsigned int	pow;
	char	*hex;

	hex = "0123456789ABCDEF";
	tmp = num;
	pow = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		pow *= 16;
	}
	tmp = num;
	while (pow)
	{
		ft_putchar_count_fd(hex[num / pow], 1, in_len);
		num %= pow;
		pow /= 16;
	}
}