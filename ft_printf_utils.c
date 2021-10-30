#include "ft_printf.h"
static unsigned int ft_getnbrsize(long long unsigned int n)
{
	unsigned int i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int ft_utoa_print(unsigned int n)
{
	char *str;
	unsigned int size;
	int i;

	size = ft_getnbrsize(n);
	i = size;
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (0);
	while (size)
	{
		str[(size) - 1] = (n % 10) + '0';
		n = (n / 10);
		size--;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (i);
}