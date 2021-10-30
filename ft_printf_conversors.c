#include "ft_printf.h"
#include <stdio.h>

char	*ft_convert_c(char *str, va_list args, size_t ist_start)
{
	char *s;
	char c = va_arg(args, int);

	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	str = ft_insert_str_s(str, s, ist_start - 1);
	free(s);
	return (str);
}

char *ft_convert_d_i(char *str, va_list args, size_t ist_start)
{
	char *s;
	int c = va_arg(args, int);

	s = ft_itoa(c);
	str = ft_insert_str_s(str, s, ist_start - 1);
	free(s);
	return (str);
}

// char	*ft_convert%(char *str, va_list args, size_t istStart)
// {
// 	str = ft_insert_strS(str, "%", istStart - 1);
// 	return (str);
// }