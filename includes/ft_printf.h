/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:15:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/13 15:16:26 by vtenneke      ########   odam.nl         */
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

/*
** MAIN FUNCTIONS
*/

typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *input, ...);
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(const char **input, t_conv *conv);
void			ft_set_flags(const char **input, t_conv *conv);
void			ft_call_convert(t_conv *conv, va_list a_list, int *input_len);

/*
** CONVERTERS
*/

void			ft_print_char(t_conv *conv, va_list a_list, int *input_len);
void			ft_print_str(t_conv *conv, va_list a_list, int *input_len);
void			ft_print_address(t_conv *conv, va_list a_list, int *input_len);
void			ft_print_int(t_conv *conv, va_list a_list, int *input_len);

/*
** UTILITIES
*/

void			ft_putchar_count_fd(char c, int fd, int *input_len);
int				ft_checkexist(const char **input, t_conv *conv);
void			ft_padzero(int width, int precision, int pad, int *input_len);
void			ft_putnstr_count_fd(char *str, int fd, int n, int *input_len);
// int				ft_nbr_size(int i, t_conv *conv);
// void			ft_putnbr_count_fd(int n, int fd, int *input_len);

#endif
