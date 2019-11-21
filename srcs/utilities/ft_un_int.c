/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_un_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:19:53 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 13:01:51 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	ft_prep_un_int(t_conv *conv, unsigned int *i)
{
	conv->size = ft_putint_un_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *i != 0))
		conv->precision = conv->size;
}

int		ft_putint_un_size(unsigned int i)
{
	unsigned int	tmp;
	int				size;

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

void	ft_putint_un_count_fd(unsigned int i, int *in_len)
{
	unsigned int		tmp;
	unsigned int		pow;

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

