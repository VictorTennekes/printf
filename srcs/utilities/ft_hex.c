/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:18:18 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 13:02:34 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	ft_prephex_int(t_conv *conv, unsigned int *num)
{
	if (conv->size == 'l')
		*num = (long)*num;
	conv->size = ft_puthex_size(*num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *num != 0))
		conv->precision = conv->size;
}

int		ft_puthex_size(unsigned int i)
{
	unsigned int	tmp;
	int				size;

	tmp = i;
	size = 0;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp = tmp / 16;
		size++;
	}
	return (size);
}

void	ft_puthex_lower_count_fd(unsigned int num, int *in_len)
{
	unsigned int	tmp;
	unsigned int	pow;
	char			*hex;

	hex = "0123456789abcdef";
	tmp = num;
	pow = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		pow *= 16;
	}
	tmp = num;
	while (pow)
	{
		ft_putchar_count_fd(hex[num / pow], 1, in_len);
		num %= pow;
		pow /= 16;
	}
}

void	ft_puthex_upper_count_fd(unsigned int num, int *in_len)
{
	unsigned int	tmp;
	unsigned int	pow;
	char			*hex;

	hex = "0123456789ABCDEF";
	tmp = num;
	pow = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		pow *= 16;
	}
	tmp = num;
	while (pow)
	{
		ft_putchar_count_fd(hex[num / pow], 1, in_len);
		num %= pow;
		pow /= 16;
	}
}
