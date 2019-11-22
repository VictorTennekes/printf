/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_un.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:48:48 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 13:49:28 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_print_un_int(t_conv *conv, va_list a_list, int *in_len)
{
	unsigned int num;

	if (conv->sizemod == 1)
		return (ft_ll_num(conv, a_list, in_len));
	if (conv->sizemod == 2)
		return (ft_l_num(conv, a_list, in_len));
	num = va_arg(a_list, unsigned int);
	ft_prep_un_int(conv, &num);
	if (conv->hassign && (conv->leftj || conv->padzero))
		ft_putchar_count_fd(conv->sign, 1, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_un_count_fd(num, in_len);
	}
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision + conv->hassign, '0', in_len);
	else
		ft_pad(conv->width, conv->precision + conv->hassign, ' ', in_len);
	if (!conv->leftj)
	{
		if (conv->hassign && !conv->padzero)
			ft_putchar_count_fd(conv->sign, 1, in_len);
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_putint_un_count_fd(num, in_len);
	}
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
