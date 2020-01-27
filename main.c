#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
	char c = '\0';
	unsigned long num = 200;

	printf("echte = [%+5.0d]\n", 0);
	ft_printf("neppe = [%+5.0d]\n", 0);

	printf("echte = [%c]\n", c);
	ft_printf("neppe = [%c]\n", c);
}
