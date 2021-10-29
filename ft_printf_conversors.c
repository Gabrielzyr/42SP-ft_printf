#include "ft_printf.h"

// char	*ft_convertC(char *str, va_list args, size_t istStart)
// {
// 	char *s;
// 	char c = va_arg(args, int);

// 	s = ft_strdup("");
// 	s[0] = c;
// 	str = ft_insert_strS(str, s, istStart);

// 	return (str);
// }

// char *ft_convertD(char *str, va_list args, size_t istStart)
// {
// 	char *s;
// 	int c = va_arg(args, int);

// 	s = ft_itoa(c);
// 	str = ft_insert_strS(str, s, istStart - 1);
// 	return (str);
// }