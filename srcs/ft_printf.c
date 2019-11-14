/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:42:07 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/14 15:50:00 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdio.h>

void	ft_init_conv_vars(t_conv *conv)
{
	conv->type = 0;
	conv->width = 0;
	conv->precision = -2;
	conv->leftj = 0;
	conv->padzero = 0;
	conv->sign = 0;
	conv->various = 0;
	conv->size = 0;
}

void	ft_set_conv_vars(const char **input, t_conv *conv)
{
	char *type;

	*input += 1;
	while (**input)
	{
		type = "cspdiuxXnfge%";
		while (*type)
		{
			if (**input == *type)
			{
				conv->type = *type;
				return ;
			}
			type++;
		}
		ft_set_flags(input, conv);
		*input += 1;
	}
}

void	ft_set_flags(const char **input, t_conv *conv)
{
	if (**input == '-')
		conv->leftj = 1;
	else if (**input == '0')
		conv->padzero = 1;
	else if (**input == '+' || **input == ' ')
	{
		conv->sign = **input;
		conv->hassign = 1;
	}
	else if (**input == '*')
		conv->width = -1;
	else if (ft_isdigit(**input))
		conv->width = ft_atoi(*input);
	else if (**input == '.' && *(*input + 1) == '*')
		conv->precision = -1;
	else if (**input == '.' && ft_isdigit(*(*input + 1)))
		conv->precision = ft_atoi(*input + 1);
	else if (**input == '.')
		conv->precision = 0;
	if ((**input == '.' && *(*input + 1) == '*') ||
		(**input == '.' && ft_isdigit(*(*input + 1))))
		*input += 1;
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*input)) && ft_isdigit(*(*input + 1)))
			*input += 1;
}

void	ft_call_convert(t_conv *conv, va_list a_list, int *input_len)
{
	char	*types;
	t_cfunc	functions[13];
	int		i;

	types = "cspdiUxXnfge%";
	functions[0] = &ft_print_char;
	functions[1] = &ft_print_str;
	functions[2] = &ft_print_address;
	functions[3] = &ft_print_int;
	functions[4] = &ft_print_int;
	// functions[5] = ;
	// functions[6] = ;
	// functions[7] = ;
	// functions[8] = ;
	// functions[9] = ;
	// functions[10] = ;
	// functions[11] = ;
	// functions[12] = ;
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			functions[i](conv, a_list, input_len);
		i++;
	}
}

int				ft_printf(const char *input, ...)
{
	va_list a_list;
	t_conv	conv;
	int		input_len;

	va_start(a_list, input);
	input_len = 0;
	while (*input)
	{
		if (*input != '%')
		{
			ft_putchar_fd(*input, 1);
			input_len++;
		}
		else
		{
			ft_init_conv_vars(&conv);
			ft_set_conv_vars(&input, &conv);
			if (conv.width == -1)
				conv.width = va_arg(a_list, int);
			if (conv.precision == -1)
				conv.precision = va_arg(a_list, int);
			ft_call_convert(&conv, a_list, &input_len);
		}
		input++;
	}
	va_end(a_list);
	return (input_len);
}
