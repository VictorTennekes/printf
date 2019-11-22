/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 10:52:37 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/22 14:09:04 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_print_char(t_conv *conv, va_list a_list, int *in_len)
{
	int c;

	c = va_arg(a_list, int);
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd(c, 1, in_len);
	ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!(conv->leftj))
		ft_putchar_count_fd(c, 1, in_len);
}

void	ft_print_str(t_conv *conv, va_list a_list, int *in_len)
{
	char	*str;
	int		len;

	str = va_arg(a_list, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (len < conv->precision || conv->precision == -2)
		conv->precision = len;
	if (conv->leftj)
		ft_putnstr_count_fd(str, 1, conv->precision, in_len);
	if (!conv->leftj && conv->padzero)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!(conv->leftj))
		ft_putnstr_count_fd(str, 1, conv->precision, in_len);
}

void	ft_print_percent(t_conv *conv, va_list a_list, int *in_len)
{
	if (conv->precision == -2)
		conv->precision = 1;
	if (conv->leftj)
		ft_putchar_count_fd('%', 1, in_len);
	if (conv->padzero && !conv->leftj)
		ft_pad(conv->width, conv->precision, '0', in_len);
	else
		ft_pad(conv->width, conv->precision, ' ', in_len);
	if (!conv->leftj)
		ft_putchar_count_fd('%', 1, in_len);
}

void	ft_putchar_count_fd(char c, int fd, int *in_len)
{
	ft_putchar_fd(c, fd);
	*in_len += 1;
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *in_len)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar_count_fd(str[i], fd, in_len);
		i++;
	}
}
