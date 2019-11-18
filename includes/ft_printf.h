/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:15:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/18 15:14:15 by vtenneke      ########   odam.nl         */
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
	int			hassign;
	int			sizemod;
	int			size;
}				t_conv;

/*
** MAIN FUNCTIONS
*/
typedef void	(*t_cfunc)(t_conv *, va_list, int *);
int				ft_printf(const char *input, ...);
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(t_conv *conv, const char **input);
void			ft_set_flags(t_conv *conv, const char **input);
void			ft_call_convert(t_conv *conv, va_list a_list, int *in_len);

/*
** CONVERTERS
*/
void			ft_print_char(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_str(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_address(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_int(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_un_int(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_lower_hex(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_upper_hex(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_percent(t_conv *conv, va_list a_list, int *in_len);

/*
** CHARS AND STRINGS
*/
void			ft_putchar_count_fd(char c, int fd, int *in_len);
int				ft_checkexist(const char **input, t_conv *conv);
void			ft_pad(int width, int precision, int pad, int *in_len);
void			ft_putnstr_count_fd(char *str, int fd, int n, int *in_len);

/*
** ADDRESS
*/
void			ft_put_address(unsigned long address, int *in_len);

/*
**  INT AND DECIMAL
*/
void			ft_prep_int(t_conv *conv, int *i);
int				ft_putint_size(int i, t_conv *conv);
void			ft_putint_count_fd(int i, int *in_len);

/*
** UNSIGNED INT
*/
void			ft_putint_un_count_fd(unsigned int i, int *in_len);
int				ft_putint_un_size(unsigned int i, t_conv *conv);
void			ft_prep_un_int(t_conv *conv, unsigned int i);

/*
** HEX LOWER AND UPPER
*/
void			ft_prephex_int(t_conv *conv, unsigned int num);
int				ft_puthex_size(unsigned int num, t_conv *conv);
void			ft_puthex_lower_count_fd(unsigned int num, int *in_len);
void			ft_puthex_upper_count_fd(unsigned int num, int *in_len);

/*
** SIZE MODIFIERS
*/
void			ft_size_num(t_conv *conv, va_list a_list, int *lv);
void			ft_ll_num(t_conv *conv, va_list a_list, int *lv);
void			ft_llint_c_fd(long long int num, int *lv);
long long int	ft_ll_nbr_size(t_conv *conv, long long int num);
void			ft_conv_ll_int(t_conv *conv, long long int num);

#endif
