/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_converters_fge.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:41:50 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/21 12:44:52 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <unistd.h>

void		ft_print_float(t_conv *conv, va_list a_list, int *in_len)
{
	write(1, "FLOAT!", 7);
}

void		ft_print_significant(t_conv *conv, va_list a_list, int *in_len)
{
	write(1, "SIGNIFICANT!", 7);
}

void		ft_print_scientific(t_conv *conv, va_list a_list, int *in_len)
{
	write(1, "SCIENTIFIC!", 7);
}
