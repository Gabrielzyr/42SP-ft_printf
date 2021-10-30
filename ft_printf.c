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

int ft_get_str_type(char *str, size_t ist_start, va_list args)
{
	int length;
	// char *new_str;
	length = 0;
	if (str[ist_start] == 'c')
		length = ft_convert_c(args);
	else if (str[ist_start] == 's')
		length = ft_convert_s(va_arg(args, char *));
	else if (str[ist_start] == 'd' || str[ist_start] == 'i')
		length = ft_convert_d_i(args);
	else if (str[ist_start] == 'x' || str[ist_start] == 'X')
		length = ft_convert_x(va_arg(args, unsigned int), str[ist_start]);
	else if (str[ist_start] == 'p')
		length = ft_convert_p(va_arg(args, size_t));
	else if (str[ist_start] == 'u')
		length = ft_convert_u(args);
	else if (str[ist_start] == '%')
	{
		write(1, "%", 1);
		length = 1;
	}
		return (length);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	size_t i;
	char *final_str;
	int flag;
	size_t length;

	final_str = (char *)str;
	va_start(args, str);
	i = 0;
	length = 0;
	while (final_str[i])
	{
		flag = 0;
		if (final_str[i] == '%')
		{
			i++;
			if (ft_strchr("cspdiuxX%", final_str[i]))
			{
				length += ft_get_str_type(final_str, i, args);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			length++;
			write(1, &final_str[i], 1);
		}
		i++;
	}
	va_end(args);
	// ft_print_str(final_str);
	// free(final_str);
	return (length);
}

