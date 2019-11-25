/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prep_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:59:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 15:45:22 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_prep_l_int(t_conv *conv, long int *num)
{
	if (*num < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->size = ft_l_nbr_size(*num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *num != 0))
		conv->precision = conv->size;
}

void	ft_prep_ll_int(t_conv *conv, long long int *num)
{
	if (*num < 0)
	{
		conv->hassign = 1;
		conv->sign = '-';
	}
	conv->size = ft_ll_nbr_size(*num);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *num != 0))
		conv->precision = conv->size;
}

void	ft_prep_un_int(t_conv *conv, unsigned int *i)
{
	if (conv->sizemod == 3)
		*i = (unsigned short)*i;
	if (conv->sizemod == 4)
		*i = (unsigned char)*i;
	conv->size = ft_putint_un_size(*i);
	if (conv->precision != -2)
		conv->padzero = 0;
	if (conv->precision == -2 ||
		(conv->precision < conv->size && *i != 0))
		conv->precision = conv->size;
}
