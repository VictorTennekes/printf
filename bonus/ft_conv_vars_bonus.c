/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_vars.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:47:37 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 09:43:55 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

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

void	ft_size_check(t_conv *conv, const char **input)
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

void	ft_precision_check(t_conv *conv, const char **input)
{
	if (**input == '.' && *(*input + 1) == '*')
		conv->precision = -1;
	else if (**input == '.' && ft_isdigit(*(*input + 1)))
		conv->precision = ft_atoi(*input + 1);
	else if (**input == '.')
		conv->precision = 0;
	if ((**input == '.' && *(*input + 1) == '*') ||
		(**input == '.' && ft_isdigit(*(*input + 1))))
		*input += 1;
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
	ft_precision_check(conv, input);
	if (conv->precision != -2 || conv->width != 0)
		while (ft_isdigit(*(*input)) && ft_isdigit(*(*input + 1)))
			*input += 1;
	ft_size_check(conv, input);
}
