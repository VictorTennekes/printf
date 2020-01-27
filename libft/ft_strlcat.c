/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:12:05 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/05 14:10:31 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t tmp;

	dstlen = 0;
	tmp = 0;
	while (dst[dstlen])
		dstlen++;
	while (tmp < dstsize - dstlen - 1 && src[tmp] && dstsize > dstlen)
	{
		dst[dstlen + tmp] = src[tmp];
		tmp++;
	}
	dst[dstlen + tmp] = '\0';
	while (src[tmp] != '\0')
		tmp++;
	if (dstsize < dstlen)
		return (tmp + dstsize);
	return (dstlen + tmp);
}
