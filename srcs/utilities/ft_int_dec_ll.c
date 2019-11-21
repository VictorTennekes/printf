/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_dec_ll.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:11:56 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 13:03:37 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void			ft_ll_num(t_conv *conv, va_list a_list, int *in_len)
{
	long long int num;

	num = va_arg(a_list, long long int);
	ft_prep_ll_int(conv, num);
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

void			ft_llint_c_fd(long long int num, int *in_len)
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

int	ft_ll_nbr_size(long long int num)
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

void			ft_prep_ll_int(t_conv *conv, long long int num)
{
	if (num < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->size = ft_ll_nbr_size(num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && conv->precision != 0))
		conv->precision = conv->size;
}
