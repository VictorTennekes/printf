/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:15:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/11 22:54:27 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_conv
{
	char		specifier;
	int			width;
	int			precision;
	int			leftj;
	int			padzero;
	int			sign;
}				t_conv;

int			ft_printf(const char *input, ...);
void		ft_init_conv_vars(t_conv *conv);
void		ft_set_conv_vars(const char **input, t_conv *conv);

#endif