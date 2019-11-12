/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 12:16:44 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/12 22:50:19 by victor        ########   odam.nl         */
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
}

void	ft_check_flags(const char **input, t_conv *conv)
{
	if (**input == '-')
		conv->leftj = 1;
	else if (**input == '0')
		conv->padzero = 1;
	else if (**input == '+' || **input == ' ')
		conv->sign = **input;
	else if (**input == '#')
		conv->various = 1;
	else if (**input == '*')
		conv->width = -1;
	else if (ft_isdigit(**input))
		conv->width = ft_atoi(*input);
	else if (**input == '.')
	{
		if (**input + 1 == '*')
			conv->precision = -1;
		else if (ft_isdigit(*(*input + 1)))
			conv->precision = ft_atoi(*input + 1);
		else
			conv->precision = 0;
		*input += 1;
	}
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*input)) && ft_isdigit(*(*input + 1)))
			*input += 1;
}

void	ft_set_conv_vars(const char **input, t_conv *conv)
{
	char *type;

	if (ft_checkexist(input, conv))
		return ;
	*input += 1;
	while (**input)
	{
		type = "cspdiuxX%";
		while (*type)
		{
			if (**input == *type)
			{
				conv->type = *type;
				return ;
			}
			type++;
		}
		ft_check_flags(input, conv);
		if (ft_checkexist(input, conv))
		return ;
		*input += 1;
	}
}

void	ft_call_convert(t_conv *conv, va_list a_list, int *input_len)
{
	char	*types;
	t_cfunc	funcs[13];
	int		i;

	types = "cspdiUxXnfge%";
	funcs[0] = &ft_print_char;
	funcs[1] = &ft_print_str;
	funcs[2] = &ft_print_adress;
	funcs[3] = &ft_print_double;
	// funcs[4] = ;
	// funcs[5] = ;
	// funcs[6] = ;
	// funcs[7] = ;
	// funcs[8] = ;
	// funcs[9] = ;
	// funcs[10] = ;
	// funcs[11] = ;
	// funcs[12] = ;
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			funcs[i](conv, a_list, input_len);
		i++;
	}
}

int		ft_printf(const char *input, ...)
{
	t_conv	conv;
	va_list a_list;
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