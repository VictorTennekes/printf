/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prep_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 11:06:16 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 16:53:35 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_prephex(t_conv *conv, unsigned int *num)
{
	if (conv->sizemod == 3)
		*num = ((unsigned short)*num);
	if (conv->sizemod == 4)
		*num = ((unsigned char)*num);
	conv->size = ft_puthex_size(*num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (*num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *num != 0))
		conv->precision = conv->size;
}

void	ft_prephex_l(t_conv *conv, unsigned long *num)
{
	if (conv->sizemod == 3)
		*num = ((unsigned short)*num);
	if (conv->sizemod == 4)
		*num = ((unsigned char)*num);
	conv->size = ft_x_l_size(*num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *num != 0))
		conv->precision = conv->size;
}

void	ft_prephex_ll(t_conv *conv, unsigned long long *num)
{
	if (conv->sizemod == 3)
		*num = ((unsigned short)*num);
	if (conv->sizemod == 4)
		*num = ((unsigned char)*num);
	conv->size = ft_x_ll_size(*num);
	if (conv->precision != -2) 
		conv->padzero = 0;
	if (num == 0)
		conv->various = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size  && *num != 0))
		conv->precision = conv->size;
}
