/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters_u.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 12:32:39 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/15 15:59:29 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

void	ft_print_un_int(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned int num;

	num = va_arg(a_list, unsigned int);
	ft_prep_un_int(conv, num);
	if (conv->hassign && (conv->leftj || conv->padzero))
		ft_putchar_count_fd(conv->sign, 1, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_un_count_fd(num, in_len);
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
			ft_putint_un_count_fd(num, in_len);
	}
}

void	ft_print_lower_hex(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned int num;

	num = va_arg(a_list, unsigned int);
	ft_prephex_int(conv, num);
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

	num = va_arg(a_list, unsigned int);
	ft_prephex_int(conv, num);
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
