/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_general_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 13:47:52 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/19 13:50:12 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_valid_arg(t_conv *conv, const char **input)
{
	if (!*(*input + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}
