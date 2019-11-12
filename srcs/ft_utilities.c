/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utilities.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/12 23:02:39 by victor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>

void	ft_putchar_count_fd(char c, int fd, int *input_len)
{
	write(1, &c, fd);
	input_len += 1;
}

int		ft_checkexist(const char **format, t_conv *conv)
{
	if (!*(*format + 1))
	{
		conv->type = 0;
		return (1);
	}
	return (0);
}

void	ft_padzero(int width, int precision, int pad, int *input_len)
{
	while (width > precision)
	{
		*input_len += 1;
		ft_putchar_fd(pad, 1);
		width--;
	}
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *input_len)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0' && i < n)
	{
		input_len++;
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

int		ft_nbr_size(int i, t_conv *conv)
{
	int	tmp;
	int	size;

	tmp = i;
	size = 0;
	if (i < 0 || conv->sign)
		size++;
	if (i == 0)
		size++;
	while (tmp)
	{
		tmp /= 10;
		size++;
	}
	return (size);
}