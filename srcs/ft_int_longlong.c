/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_longlong.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:37:41 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 16:13:53 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_ll_num(t_conv *conv, va_list a_list, int *in_len)
{
	long long int num;

	num = va_arg(a_list, long long int);
	ft_prep_ll_int(conv, &num);
	if (conv->hassign && (conv->padzero || conv->leftj))
		ft_putchar_count_fd(conv->sign, 1, in_len);
	if (conv->leftj)
	{
		ft_pad(conv->precision, conv->size, '0', in_len);
		if (conv->precision)
			ft_llint_c_fd(num, in_len);
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
			ft_llint_c_fd(num, in_len);
	}
}

void	ft_llint_c_fd(long long int num, int *in_len)
{
	long long int		res;
	long long int		pow;

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

int		ft_ll_nbr_size(long long int num)
{
	long long int		tmp;
	int					size;

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
