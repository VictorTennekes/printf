/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_un_int_long.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 15:50:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 16:03:25 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_print_un_int_l(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned long int num;

	num = va_arg(a_list, unsigned long int);
	ft_prep_un_int_l(conv, &num);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_un_l_count(num, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_un_l_count(num, in_len);
	}
}

int		ft_putint_un_size_l(unsigned long int i)
{
	unsigned long int	tmp;
	int					size;

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

void	ft_putint_un_l_count(unsigned long int i, int *in_len)
{
	unsigned long int		tmp;
	unsigned long int		pow;

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

void	ft_prep_un_int_l(t_conv *conv, unsigned long int *i)
{
	if (conv->sizemod == 3)
		*i = (unsigned short)*i;
	if (conv->sizemod == 4)
		*i = (unsigned char)*i;
	conv->size = ft_putint_un_size_l(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *i != 0))
		conv->precision = conv->size;
}
