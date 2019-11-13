/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utilities.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:20:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/13 15:24:19 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putchar_count_fd(char c, int fd, int *input_len)
{
	ft_putchar_fd(c, fd);
	input_len += 1;
}

void	ft_padzero(int width, int precision, int pad, int *input_len)
{
	while (width > precision)
	{
		ft_putchar_count_fd(pad, 1, input_len);
		width--;
	}
}

void	ft_putnstr_count_fd(char *str, int fd, int n, int *input_len)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar_count_fd(str[i], fd, input_len);
		i++;
	}
}

// int		ft_nbr_size(int i, t_conv *conv)
// {
// 	int	tmp;
// 	int	size;

// 	tmp = i;
// 	size = 0;
// 	if (i < 0 || conv->sign)
// 		size++;
// 	if (i == 0)
// 		size++;
// 	while (tmp)
// 	{
// 		tmp /= 10;
// 		size++;
// 	}
// 	return (size);
// }

// void		ft_putnbr_count_fd(int n, int fd, int *input_len)
// {
// 	unsigned int		res;

// 	res = 0;
// 	if (n < 0)
// 	{
// 		ft_putchar_count_fd('-', fd, input_len);
// 		res = (unsigned int)(n * -1);
// 	}
// 	else
// 		res = (unsigned int)n;
// 	if (res >= 10)
// 		ft_putnbr_fd(res / 10, fd);
// 	ft_putchar_count_fd((char)(res % 10 + '0'), fd, input_len);
// }
