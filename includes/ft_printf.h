/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:15:40 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/26 09:18:31 by vtenneke      ########   odam.nl         */
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

typedef void	(*t_cfunc)(t_conv *, va_list, int *);

/*
** ft_char_string
*/
void			ft_print_char(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_str(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_percent(t_conv *conv, int *in_len);
void			ft_putchar_count_fd(char c, int fd, int *in_len);
void			ft_putnstr_count_fd(char *str, int fd, int n, int *in_len);

/*
** ft_conv_vars
*/
void			ft_init_conv_vars(t_conv *conv);
void			ft_set_conv_vars(t_conv *conv, const char **input);
void			ft_size_check(t_conv *conv, const char **input);
void			ft_precision_check(t_conv *conv, const char **input);
void			ft_set_flags(t_conv *conv, const char **input);

/*
** ft_hex_long
*/
void			ft_print_l_x(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_l_up_x(t_conv *conv, va_list a_list, int *in_len);
int				ft_x_l_size(unsigned long num);
void			ft_x_res_l_c_fd(unsigned long num, int *in_len);
void			ft_upx_res_l_c_fd(unsigned long num, int *in_len);

/*
** ft_hex_longlong
*/
void			ft_print_ll_x(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_ll_up_x(t_conv *conv, va_list a_list, int *in_len);
int				ft_x_ll_size(unsigned long long num);
void			ft_x_res_ll_c_fd(unsigned long long num, int *in_len);
void			ft_upx_res_ll_c_fd(unsigned long long num, int *in_len);

/*
** ft_int_long
*/
void			ft_l_num(t_conv *conv, va_list a_list, int *in_len);
void			ft_lint_c_fd(long int num, int *in_len);
int				ft_l_nbr_size(long int num);

/*
** ft_int_longlong
*/
void			ft_ll_num(t_conv *conv, va_list a_list, int *in_len);
void			ft_llint_c_fd(long long int num, int *in_len);
int				ft_ll_nbr_size(long long int num);

/*
** ft_int_longlong
*/
void			ft_pad(int width, int precision, int pad, int *in_len);
int				ft_valid_arg(t_conv *conv, const char **input);
void			ft_call_convert(t_conv *conv, va_list a_list, int *in_len);

/*
** ft_prep_hex
*/
void			ft_prephex(t_conv *conv, unsigned int *num);
void			ft_prephex_l(t_conv *conv, unsigned long *num);
void			ft_prephex_ll(t_conv *conv, unsigned long long *num);

/*
** ft_prep_hex
*/
void			ft_prep_int(t_conv *conv, int *i);
void			ft_prep_l_int(t_conv *conv, long int *num);
void			ft_prep_ll_int(t_conv *conv, long long int *num);
void			ft_prep_un_int(t_conv *conv, unsigned int *i);

/*
** ft_print_hex
*/
void			ft_print_lower_hex(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_upper_hex(t_conv *conv, va_list a_list, int *in_len);
void			ft_puthex_lower_count_fd(unsigned int num, int *in_len);
void			ft_puthex_upper_count_fd(unsigned int num, int *in_len);
int				ft_puthex_size(unsigned int i);

/*
** ft_print_int
*/
void			ft_print_int(t_conv *conv, va_list a_list, int *in_len);
void			ft_print_count(va_list a_list, int *in_len);
int				ft_putint_size(int i);
void			ft_putint_count_fd(int i, int *in_len);

/*
** ft_prep_size
*/
void			ft_prep_size_int(t_conv *conv, va_list a_list, int *in_len);
void			ft_prep_size_un_int(t_conv *conv, va_list a_list, int *in_len);
void			ft_size_lower_hex(t_conv *conv, va_list a_list, int *in_len);
void			ft_size_upper_hex(t_conv *conv, va_list a_list, int *in_len);

/*
** ft_print_pointer
*/
void			ft_print_pointer(t_conv *conv, va_list a_list, int *in_len);
unsigned long	ft_ptr_size(unsigned long ptr);
void			ft_ptr_res_fd(unsigned long ptr, int *in_len);

/*
** ft_print_un
*/
void			ft_print_un_int(t_conv *conv, va_list a_list, int *in_len);
int				ft_putint_un_size(unsigned int i);
void			ft_putint_un_count_fd(unsigned int i, int *in_len);

/*
** ft_printf
*/
int				ft_printf(const char *input, ...);

/*
** ft_un_int_long
*/
void			ft_print_un_int_l(t_conv *conv, va_list a_list, int *in_len);
int				ft_putint_un_size_l(unsigned long int i);
void			ft_putint_un_l_count(unsigned long int i, int *in_len);
void			ft_prep_un_int_l(t_conv *conv, unsigned long int *i);

/*
** ft_un_int_longlong
*/
void			ft_print_un_int_ll(t_conv *conv, va_list a_list, int *in_len);
int				ft_putint_un_size_ll(unsigned long long int i);
void			ft_putint_un_ll_count(unsigned long long int i, int *in_len);
void			ft_prep_un_int_ll(t_conv *conv, unsigned long long int *i);

#endif
