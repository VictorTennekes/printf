/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_general_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 13:47:52 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 13:00:08 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				ft_valid_arg(t_conv *conv, const char **input)
{
	if (!*(*input + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}

unsigned long	ft_ptr_size(unsigned long ptr)
{
	unsigned long	tmp;
	unsigned long	size;

	size = 0;
	tmp = ptr;
	if (ptr == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void			ft_ptr_res_fd(unsigned long ptr, int *in_len)
{
	unsigned long	res;
	unsigned long	power;
	char			*hex;

	hex = "0123456789abcdef";
	res = ptr;
	power = 1;
	while (res / 16)
	{
		res /= 16;
		power *= 16;
	}
	res = ptr;
	while (power)
	{
		ft_putchar_count_fd(hex[ptr / power], 1, in_len);
		ptr %= power;
		power /= 16;
	}
}
