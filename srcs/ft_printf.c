/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:30:51 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/11 16:40:58 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

t_data		*ft_checkconv(const char *input)
{
	t_data	*data;

	data = (t_data*)malloc(sizeof(t_data));
	if (ft_strncmp(input, "%", 1))
	{
		input++;
		if (ft_strncmp(input, "-", 1))
			data->flags = 1;
		if (ft_strncmp(input, "0", 1))
			data->flags = 2;
		if (ft_strncmp(input, ".", 1))
			data->flags = 3;
		if (ft_strncmp(input, "*", 1))
			data->flags = 4;
		if (ft_strncmp(input, "c", 1))
			data->converter = 1;
		if (ft_strncmp(input, "s", 1))
			data->converter = 2;
		if (ft_strncmp(input, "p", 1))
			data->converter = 3;
		if (ft_strncmp(input, "d", 1))
			data->converter = 4;
		if (ft_strncmp(input, "i", 1))
			data->converter = 5;
		if (ft_strncmp(input, "u", 1))
			data->converter = 6;
		if (ft_strncmp(input, "x", 1))
			data->converter = 7;
		if (ft_strncmp(input, "X", 1))
			data->converter = 8;
		if (ft_strncmp(input, "%", 1))
			data->converter = 9;
		printf("%i", data->converter);
	}
	return (data);
}

int		ft_printf(const char *input, ...)
{
	t_data *conv_flag;
	int		test;

	test = 27;
	while (*input)
	{
		if (ft_strncmp(input, "%", 1))
		{
			conv_flag = ft_checkconv(input);
			if (conv_flag->converter == 5)
				ft_putstr_fd(ft_itoa(test), 1);
		}
		else
			ft_putchar_fd((char)input, 1);
		input++;
	}
	return (ft_strlen(input));
}

int		main(void)
{
	ft_printf("%i");
	ft_putchar_fd('\n', 1);
	return (0);
}