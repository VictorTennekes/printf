/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex_ll.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 11:13:57 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/19 13:14:30 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void		ft_print_ll_x(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned long long	num;

	num = va_arg(a_list, unsigned long long);
	ft_conv_ll_x(conv, &num);
	if (conv->various && num != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_count_fd("0x", 1, 2, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_x_res_ll_c_fd(num, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision + (conv->various * 2), '0', in_len);
	else
		ft_pad(conv->width, conv->precision + (conv->various * 2), ' ', in_len);
	if (!conv->leftj)
	{
		if (conv->various && num != 0 && !conv->padzero)
			ft_putnstr_count_fd("0x", 1, 2, in_len);
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_x_res_ll_c_fd(num, in_len);
	}
}

int			ft_x_ll_size(t_conv *conv, unsigned long long num)
{
	unsigned long long	tmp;
	int					size;

	size = 0;
	tmp = num;
	if (num == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void		ft_conv_ll_x(t_conv *conv, unsigned long long *num)
{
	if (conv->size == 3)
		*num = ((unsigned short)*num);
	if (conv->size == 4)
		*num = ((unsigned char)*num);
	conv->size = ft_x_ll_size(conv, *num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
}

void		ft_x_res_ll_c_fd(unsigned long long num, int *in_len)
{
	unsigned long long	res;
	unsigned long long	power;
	char				*hex;

	hex = "0123456789abcdef";
	res = num;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = num;
	while (power)
	{
		ft_putchar_count_fd(hex[num / power], 1, in_len);
		num %= power;
		power /= 16;
	}
}

void		ft_upx_res_ll_c_fd(unsigned long long num, int *in_len)
{
	unsigned long long	res;
	unsigned long long	power;
	char				*hex;

	hex = "0123456789ABCDEF";
	res = num;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = num;
	while (power)
	{
		ft_putchar_count_fd(hex[num / power], 1, in_len);
		num %= power;
		power /= 16;
	}
}

void		ft_print_ll_up_x(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned long long	num;

	num = va_arg(a_list, unsigned long long);
	ft_conv_ll_x(conv, &num);
	if (conv->various && num != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_count_fd("0X", 1, 2, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_upx_res_ll_c_fd(num, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision + (conv->various * 2), '0', in_len);
	else
		ft_pad(conv->width, conv->precision + (conv->various * 2), ' ', in_len);
	if (!conv->leftj)
	{
		if (conv->various && num != 0 && !conv->padzero)
			ft_putnstr_count_fd("0X", 1, 2, in_len);
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_upx_res_ll_c_fd(num, in_len);
	}
}
