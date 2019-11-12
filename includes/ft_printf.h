/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:15:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/12 17:21:43 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_conv
{
	char		type;
	int			width;
	int			precision;
	int			leftj;
	int			padzero;
	int			various;
	char		sign;
}				t_conv;

typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *input, ...);
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(const char **input, t_conv *conv);
void			ft_check_flags(const char **input, t_conv *conv);

void			ft_print_char(t_conv *conv, va_list a_list, int *input_len);
void			ft_print_str(t_conv *conv, va_list a_list, int *input_len);
void			ft_putnstr_count_fd(char *str, int fd, int n, int *input_len);
void			ft_padzero(int width, int precision, int pad, int *input_len);

#endif
