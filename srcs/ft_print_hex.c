/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:38:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 14:14:36 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_print_lower_hex(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned int num;

	if (conv->sizemod == 1)
		return (ft_print_ll_x(conv, a_list, in_len));
	if (conv->sizemod == 2)
		return (ft_print_l_x(conv, a_list, in_len));
	num = va_arg(a_list, unsigned int);
	ft_prephex(conv, &num);
	if (conv->various && num != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_count_fd("0x", 1, 2, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_puthex_lower_count_fd(num, in_len);
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
			ft_puthex_lower_count_fd(num, in_len);
	}
}

void	ft_print_upper_hex(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned int num;

	if (conv->sizemod == 1)
		return (ft_print_ll_up_x(conv, a_list, in_len));
	if (conv->sizemod == 2)
		return (ft_print_l_up_x(conv, a_list, in_len));
	num = va_arg(a_list, unsigned int);
	ft_prephex(conv, &num);
	if (conv->various && num != 0 && (conv->leftj || conv->padzero))
		ft_putnstr_count_fd("0X", 1, 2, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_puthex_upper_count_fd(num, in_len);
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
			ft_puthex_upper_count_fd(num, in_len);
	}
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
	char			*hex;

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

int		ft_puthex_size(unsigned int i)
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
