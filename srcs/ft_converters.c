/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:46 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/13 15:25:36 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

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

// void	ft_print_address(t_conv *conv, va_list a_list, int *input_len)
// {
// 	// void			*output;
// 	// unsigned long	address;

// 	// output = va_args(a_list, void*);
// 	// address = (unsigned long)(output);
// 	// ft_putstr_count_fd("0x", 1, 2, input_len);
// 	//THIS DEFINITELY DOES STUFF
// }

// void	ft_print_int(t_conv *conv, va_list a_list, int *input_len)
// {
// 	int	num;
// 	int	numlen;

// 	num = va_arg(a_list, int);
// 	numlen = ft_nbr_size(num, conv);
// 	ft_putnbr_count_fd(num, 1, input_len);
// }
