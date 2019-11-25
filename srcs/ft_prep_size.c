/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_prep_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 09:48:30 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/25 10:06:11 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_prep_size_int(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->sizemod == 1)
		return (ft_ll_num(conv, a_list, in_len));
	else if (conv->sizemod == 2)
		return (ft_l_num(conv, a_list, in_len));
	else
		return (ft_print_int(conv, a_list, in_len));
}

void	ft_prep_size_un_int(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->sizemod == 1)
		return (ft_ll_num(conv, a_list, in_len));
	else if (conv->sizemod == 2)
		return (ft_l_num(conv, a_list, in_len));
	else
		return (ft_print_un_int(conv, a_list, in_len));
}

void	ft_size_lower_hex(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->sizemod == 1)
		return (ft_print_ll_x(conv, a_list, in_len));
	else if (conv->sizemod == 2)
		return (ft_print_l_x(conv, a_list, in_len));
	else
		return (ft_print_lower_hex(conv, a_list, in_len));
}

void	ft_size_upper_hex(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->sizemod == 1)
		return (ft_print_ll_up_x(conv, a_list, in_len));
	else if (conv->sizemod == 2)
		return (ft_print_l_up_x(conv, a_list, in_len));
	else
		return (ft_print_upper_hex(conv, a_list, in_len));
}
