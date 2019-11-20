/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:42:07 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/20 16:32:41 by vtenneke      ########   odam.nl         */
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
	conv->various = 0;
	conv->sign = 0;
	conv->hassign = 0;
	conv->sizemod = 0;
	conv->size = 0;
}

void	ft_set_conv_vars(t_conv *conv, const char **input)
{
	char *type;

	if (ft_valid_arg(conv, input))
		return ;
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
		ft_set_flags(conv, input);
		if (ft_valid_arg(conv, input))
			return ;
		*input += 1;
	}
}

void			ft_size_check(t_conv *conv, const char **input)
{
	if (*(*input + 1) == 'l' && **input == 'l')
	{
		conv->sizemod = 1;
		*input += 1;
	}
	else if (*(*input + 1) != 'l' && **input == 'l')
		conv->sizemod = 2;
	else if (*(*input + 1) != 'h' && **input == 'h')
		conv->sizemod = 3;
	else if (*(*input + 1) == 'h' && **input == 'h')
	{
		conv->sizemod = 4;
		*input += 1;
	}
}

void	ft_set_flags(t_conv *conv, const char **input)
{
	if (**input == '#')
		conv->various = 1;
	else if (**input == '-')
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
	ft_size_check(conv, input);
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
	// functions[9] = ;
	// functions[10] = ;
	// functions[11] = ;
	functions[12] = &ft_print_percent;
	i = 0;
	while (types[i])
	{
		if (types[i] == conv->type)
			functions[i](conv, a_list, in_len);
		i++;
	}
}

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
