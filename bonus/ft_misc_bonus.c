/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_misc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:52:20 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 10:28:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pad(int width, int precision, int pad, int *in_len)
{
	while (width > precision)
	{
		ft_putchar_count_fd(pad, 1, in_len);
		width--;
	}
}

int		ft_valid_arg(t_conv *conv, const char **input)
{
	if (!*(*input + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}

void	ft_call_convert(t_conv *conv, va_list a_list, int *in_len)
{
	char	*types;
	t_cfunc	functions[8];
	int		i;

	types = "cspdiuxX";
	functions[0] = &ft_print_char;
	functions[1] = &ft_print_str;
	functions[2] = &ft_print_pointer;
	functions[3] = &ft_prep_size_int;
	functions[4] = &ft_prep_size_int;
	functions[5] = &ft_prep_size_un_int;
	functions[6] = &ft_size_lower_hex;
	functions[7] = &ft_size_upper_hex;
	if (conv->type == 'n')
		ft_print_count(a_list, in_len);
	if (conv->type == '%')
		ft_print_percent(conv, in_len);
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			functions[i](conv, a_list, in_len);
		i++;
	}
}
