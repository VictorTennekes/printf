/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters_cti.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:46 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/19 13:33:54 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

void	ft_print_char(t_conv *conv, va_list a_list, int *in_len)
{
	int c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd(c, 1, in_len);
	ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!(conv->leftj))
		ft_putchar_count_fd(c, 1, in_len);
}

void	ft_print_str(t_conv *conv, va_list a_list, int *in_len)
{
	char	*str;
	int		len;

	str = va_arg(a_list, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len < conv->precision || conv->precision == -2)
		conv->precision = len;
	if (conv->leftj)
		ft_putnstr_count_fd(str, 1, conv->precision, in_len);
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!(conv->leftj))
		ft_putnstr_count_fd(str, 1, conv->precision, in_len);
}

void			ft_print_pointer(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned long ptr;

	ptr = (unsigned long)va_arg(a_list, void*);
	ft_conv_ptr(conv, ptr);
	if (conv->precision == -2)
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

unsigned long	ft_ptr_size(t_conv *conv, unsigned long ptr)
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

void			ft_conv_ptr(t_conv *conv, unsigned long ptr)
{
	conv->size = (ft_ptr_size(conv, ptr) + 2);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (ptr == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
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

void			ft_print_percent(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd('%', 1, in_len);
	if (conv->padzero && !conv->leftj)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!conv->leftj)
		ft_putchar_count_fd('%', 1, in_len);
}

void			ft_print_int(t_conv *conv, va_list a_list, int *in_len)
{
	int num;

	if (conv->sizemod == 1 || conv->sizemod == 2)
		return (ft_ll_num(conv, a_list, in_len));
	num = va_arg(a_list, int);
	ft_prep_int(conv, &num);
	if (conv->hassign && (conv->leftj || conv->padzero))
		ft_putchar_count_fd(conv->sign, 1, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_count_fd(num, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision + conv->hassign, '0', in_len);
	else
		ft_pad(conv->width, conv->precision + conv->hassign, ' ', in_len);
	if (!conv->leftj)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_count_fd(conv->sign, 1, in_len);
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_count_fd(num, in_len);
	}
}
