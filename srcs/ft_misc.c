/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_misc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:52:20 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 14:11:31 by vtenneke      ########   odam.nl         */
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
	t_cfunc	functions[13];
	int		i;

	types = "cspdiuxXnfge%";
	functions[0] = &ft_print_char;
	functions[1] = &ft_print_str;
	functions[2] = &ft_print_pointer;
	functions[3] = &ft_print_int;
	functions[4] = &ft_print_int;
	functions[5] = &ft_print_un_int;
	functions[6] = &ft_print_lower_hex;
	functions[7] = &ft_print_upper_hex;
	functions[8] = &ft_print_count;
	// functions[9] = &ft_print_float;
	// functions[10] = &ft_print_significant;
	// functions[11] = &ft_print_scientific;
	functions[12] = &ft_print_percent;
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			functions[i](conv, a_list, in_len);
		i++;
	}
}
