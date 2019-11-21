/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:22:22 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 13:01:09 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	ft_prep_int(t_conv *conv, int *i)
{
	if (conv->sizemod == 3)
		*i = (short)*i;
	if (conv->sizemod == 4)
		*i = (char)*i;
	if (*i < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->size = ft_putint_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *i != 0))
		conv->precision = conv->size;
}

int		ft_putint_size(int i)
{
	int		tmp;
	int		size;

	tmp = i;
	size = 0;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}

void	ft_putint_count_fd(int i, int *in_len)
{
	int		tmp;
	int		pow;

	tmp = i;
	pow = 1;
	while (tmp / 10)
	{
		tmp = tmp / 10;
		pow = pow * 10;
	}
	while (pow)
	{
		ft_putchar_count_fd(((i < 0) ? '0' - i / pow :
							'0' + i / pow), 1, in_len);
		i = i % pow;
		pow = pow / 10;
	}
}
