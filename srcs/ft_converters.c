/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:46 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/14 15:49:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

void	ft_print_char(t_conv *conv, va_list a_list, int *input_len)
{
	int c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd(c, 1, input_len);
	ft_padzero(conv->width, conv->precision, ' ', input_len);
	if (!(conv->leftj))
		ft_putchar_count_fd(c, 1, input_len);
}

void	ft_print_str(t_conv *conv, va_list a_list, int *input_len)
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
		ft_putnstr_count_fd(str, 1, conv->precision, input_len);
	ft_padzero(conv->width, conv->precision, ' ', input_len);
	if (!(conv->leftj))
		ft_putnstr_count_fd(str, 1, conv->precision, input_len);
}

void	ft_print_address(t_conv *conv, va_list a_list, int *input_len)
{
	ft_putstr_fd("ADDRESS", 1);
}

void	ft_print_percent(t_conv *conv, va_list a_list, int *input_len)
{
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
	{
		*input_len += 1;
		ft_putchar_fd('%', 1);
	}
	if (conv->padzero && !conv->leftj)
		ft_padzero(conv->width, conv->precision, '0', input_len);
	else
		ft_padzero(conv->width, conv->precision, ' ', input_len);
	if (!conv->leftj)
	{
		*input_len += 1;
		ft_putchar_fd('%', 1);
	}
}

void	ft_print_int(t_conv *conv, va_list a_list, int *input_len)
{
	int		i;

	i = va_arg(a_list, int);
	ft_prep_int(conv, i);
	if ((conv->padzero || conv->leftj) && conv->hassign)
		ft_putchar_count_fd(conv->sign, 1, input_len);
	if (conv->leftj)
	{
		ft_padzero(conv->precision, conv->size, '0', input_len);
		if (conv->precision)
			ft_putint_n_fd(i, input_len);
	}
	if (conv->padzero && !conv->leftj)
		ft_padzero(conv->width, conv->precision + conv->hassign,
					'0', input_len);
	else
		ft_padzero(conv->width, conv->precision + conv->hassign,
					' ', input_len);
	if (!conv->leftj)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_count_fd(conv->sign, 1, input_len);
		ft_padzero(conv->precision, conv->size, '0', input_len);
		if (conv->precision)
			ft_putint_n_fd(i, input_len);
	}
}
