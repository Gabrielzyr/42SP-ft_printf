#include "ft_printf.h"
#include <stdio.h>

// char *ft_convertC(char *str, va_list args, size_t ist_start)
// {
// 	char *s;
// 	char c = va_arg(args, int);

// 	s = ft_calloc(2, sizeof(char));
// 	s[0] = c;
// 	str = ft_insert_strS(str, s, ist_start - 1);

// 	return (str);
// }

// char *ft_convertD(char *str, va_list args, size_t ist_start)
// {
// 	char *s;
// 	int c = va_arg(args, int);

// 	s = ft_itoa(c);
// 	str = ft_insert_strS(str, s, ist_start - 1);
// 	return (str);
// }

void ft_print_str(char *str)
{
	write(1, str, 1);
	while (*str++)
		write(1, str, 1);
}

// char *ft_strjoin_free(char *s1, char const *s2)
// {
// 	char *new_str;
// 	size_t i;
// 	size_t j;

// 	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
// 	i = 0;
// 	while (s1[i])
// 	{
// 		new_str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		new_str[i + j] = s2[j];
// 		j++;
// 	}
// 	new_str[i + j] = '\0';
// 	free(s1);
// 	return (new_str);
// }

// char *ft_insert_strS(char *str, char *inStr, size_t sub_len)
// {
// 	char *new_str;
// 	char *str_end;
// 	size_t i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	new_str = ft_substr(str, 0, sub_len);
// 	str_end = ft_substr(str, sub_len+2, i - sub_len - 2);
// 	new_str = ft_strjoin_free(new_str, inStr);
// 	new_str = ft_strjoin_free(new_str, str_end);
// 	free(str_end);
// 	return (new_str);
// }

char *ft_get_str_type(char *str, size_t ist_start, va_list args)
{
	// char *new_str;
	if (str[ist_start] == 'c')
		str = ft_convert_c(str, args, ist_start);
	else if (str[ist_start] == 's')
		str = ft_insert_str_s(str, va_arg(args, char *), ist_start - 1);
	else if (str[ist_start] == 'd' || str[ist_start] == 'i')
		str = ft_convert_d_i(str, args, ist_start);
	else if (str[ist_start] == 'x')
		str = ft_convert_x(str, va_arg(args, size_t), ist_start - 1);
	// else if (str[ist_start] == 'X')
	// 	str = ft_toupper(ft_convert_x());
	return (str);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	size_t i;
	char *final_str;

	final_str = (char *)str;
	va_start(args, str);
	i = 0;
	while (final_str[i])
	{
		if (final_str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", final_str[i]))
			{
				final_str = ft_get_str_type(final_str, i, args);
			}
		}
		i++;
	}
	va_end(args);
	ft_print_str(final_str);
	free(final_str);
	return (0);
}

