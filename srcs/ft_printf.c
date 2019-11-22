/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:50:08 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 10:50:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				ft_printf(const char *input, ...)
{
	va_list a_list;
	t_conv	conv;
	int		in_len;

	va_start(a_list, input);
	in_len = 0;
	while (*input)
	{
		if (*input != '%')
			ft_putchar_count_fd(*input, 1, &in_len);
		else
		{
			ft_init_conv_vars(&conv);
			ft_set_conv_vars(&conv, &input);
			if (conv.width == -1)
				conv.width = va_arg(a_list, int);
			if (conv.precision == -1)
				conv.precision = va_arg(a_list, int);
			ft_call_convert(&conv, a_list, &in_len);
		}
		input++;
	}
	va_end(a_list);
	return (in_len);
}
