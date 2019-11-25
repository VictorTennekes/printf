/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:51:14 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 16:59:23 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			ft_print_pointer(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned long ptr;

	ptr = (unsigned long)va_arg(a_list, void*);
	conv->size = (ft_ptr_size(ptr) + 2);
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
	if (conv->leftj)
	{
		ft_putnstr_count_fd("0x", 1, 2, in_len);
		ft_pad(conv->precision,
			conv->size - ((conv->precision > conv->size) ? 2 : 0), '0', in_len);
		if (conv->precision)
			ft_ptr_res_fd(ptr, in_len);
	}
	(!conv->leftj && conv->padzero) ? ft_pad(conv->width, conv->precision,
		'0', in_len) : ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!(conv->leftj))
	{
		ft_putnstr_count_fd("0x", 1, 2, in_len);
		ft_pad(conv->precision,
			conv->size - ((conv->precision > conv->size) ? 2 : 0), '0', in_len);
		if (conv->precision)
			ft_ptr_res_fd(ptr, in_len);
	}
}

unsigned long	ft_ptr_size(unsigned long ptr)
{
	unsigned long	tmp;
	unsigned long	size;

	size = 0;
	tmp = ptr;
	if (ptr == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void			ft_ptr_res_fd(unsigned long ptr, int *in_len)
{
	unsigned long	res;
	unsigned long	power;
	char			*hex;

	hex = "0123456789abcdef";
	res = ptr;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = ptr;
	while (power)
	{
		ft_putchar_count_fd(hex[ptr / power], 1, in_len);
		ptr %= power;
		power /= 16;
	}
}
