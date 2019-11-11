/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:30:51 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/11 22:55:01 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

/*
**	the default converter values
*/

void	ft_init_conv_vars(t_conv *conv)
{
	conv->specifier = 0;
	conv->width = 0;
	conv->precision = 6;
	conv->leftj = 0;
	conv->padzero = 0;
	conv->sign = 0;
}

void	ft_set_conv_vars(const char **input, t_conv *conv)
{
	char	*specifiers;

	*input += 1;
	specifiers = "cspdiuxX%";
	while (**input)
	{
		while (*specifiers)
		{
			if (**input == *specifiers)
			{
				conv->specifier = *specifiers;
				printf("%c", conv->specifier);
				return ;
			}
			specifiers++;
		}
		*input += 1;
	}
}

int		ft_printf(const char *input, ...)
{
	t_conv	conv;
	int		input_len;

	input_len = 0;
	while (*input)
	{
		if (*input == '%')
		{
			ft_init_conv_vars(&conv);
			ft_set_conv_vars(&input, &conv);
		}
		else
		{
			//ft_putchar_fd(*input, 1);
			input_len++;
		}
	}
	return (input_len);
}

int		main(void)
{
	ft_printf("%x");
	return (1);
}