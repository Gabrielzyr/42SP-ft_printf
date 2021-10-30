#include "ft_printf.h"
#include <stdio.h>

int	ft_convert_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

int ft_convert_d_i(va_list args)
{
	size_t i;
	char *s;

	s = ft_itoa(va_arg(args, int));
	ft_putstr_fd(s, 1);
	i = ft_strlen(s);
	free(s);
	return ((int)i);
}

int ft_convert_s(char *print_str)
{
	size_t i;

	if (!print_str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = ft_strlen(print_str);
	ft_putstr_fd(print_str, 1);
	// free(print_str);
	return ((int)i);
}

int ft_convert_u(va_list args)
{
	int i;

	i = ft_utoa_print(va_arg(args, unsigned int));
	return (i);
}