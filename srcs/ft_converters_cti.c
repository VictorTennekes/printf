/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters_cti.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:46 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/18 16:24:50 by vtenneke      ########   odam.nl         */
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

void	ft_put_address(unsigned long address, int *in_len)
{
	if (address > 15)
	{
		ft_put_address((address / 16), in_len);
		ft_put_address((address % 16), in_len);
	}
	else if (address < 10)
		ft_putchar_count_fd((address + '0'), 1, in_len);
	else
	{
		address == 10 ? ft_putchar_count_fd('a', 1, in_len) : 0;
		address == 11 ? ft_putchar_count_fd('b', 1, in_len) : 0;
		address == 12 ? ft_putchar_count_fd('c', 1, in_len) : 0;
		address == 13 ? ft_putchar_count_fd('d', 1, in_len) : 0;
		address == 14 ? ft_putchar_count_fd('e', 1, in_len) : 0;
		address == 15 ? ft_putchar_count_fd('f', 1, in_len) : 0;
	}
}

void	ft_print_address(t_conv *conv, va_list a_list, int *in_len)
{
	void			*output;
	unsigned long	address;

	output = va_arg(a_list, void*);
	address = (unsigned long)(output);
	ft_prep_un_int(conv, address);
	if (conv->leftj)
	{
		ft_putnstr_count_fd("0x", 1, 2, in_len);
		ft_put_address(address, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!conv->leftj)
	{
		ft_putnstr_count_fd("0x", 1, 2, in_len);
		ft_put_address(address, in_len);
	}
}

void	ft_print_percent(t_conv *conv, va_list a_list, int *in_len)
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

void	ft_print_int(t_conv *conv, va_list a_list, int *in_len)
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
