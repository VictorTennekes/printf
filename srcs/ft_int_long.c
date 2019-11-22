/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_long.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:36:34 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 14:00:42 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_l_num(t_conv *conv, va_list a_list, int *in_len)
{
	long int num;

	num = va_arg(a_list, long int);
	ft_prep_l_int(conv, num);
	if (conv->hassign && (conv->padzero || conv->leftj))
		ft_putchar_count_fd(conv->sign, 1, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_lint_c_fd(num, in_len);
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
			ft_lint_c_fd(num, in_len);
	}
}

void	ft_lint_c_fd(long int num, int *in_len)
{
	long int		res;
	long int		pow;

	res = num;
	pow = 1;
	while (res / 10)
	{
		res /= 10;
		pow *= 10;
	}
	while (pow)
	{
		if (num < 0)
			ft_putchar_count_fd(('0' - num / pow), 1, in_len);
		if (!(num < 0))
			ft_putchar_count_fd(('0' + num / pow), 1, in_len);
		num %= pow;
		pow /= 10;
	}
}

int	ft_l_nbr_size(long int num)
{
	long int		tmp;
	int				size;

	tmp = num;
	size = 0;
	if (num == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	return (size);
}
