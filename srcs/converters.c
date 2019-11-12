/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   converters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:46 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/12 23:03:59 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

void	ft_print_char(t_conv *conv, va_list a_list, int *input_len)
{
	int c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd(c, 1);
	ft_padzero(conv->width, conv->precision, ' ', input_len);
	if (!(conv->leftj))
		ft_putchar_count_fd(c, 1);
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
	// void			*output;
	// unsigned long	address;

	// output = va_args(a_list, void*);
	// address = (unsigned long)(output);
	// ft_putstr_count_fd("0x", 1, 2, input_len);
	//THIS DEFINITELY DOES STUFF
}

void	ft_print_double(t_conv *conv, va_list a_list, int *input_len)
{
	int i;
	int len;

	i = va_arg(a_list, int);
	len = ft_nbr_size(i, conv);
	if (conv->precision == -2)
		conv->precision = len;
	if (conv->sign && i >= 0 && (conv->padzero || conv->leftj))
		ft_putchar_count_fd(conv->sign, 1, input_len);
}