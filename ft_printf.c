#include "ft_printf.h"

#include <stdio.h>

void ft_print_str(char *str)
{
	write(1, str, 1);
	while (*str++)
		write(1, str, 1);
}

char *ft_strjoin_free(char *s1, char const *s2)
{
	char *new_str;
	size_t i;
	size_t j;

	new_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

char *ft_insert_strS(char *str, char *inStr, size_t sub_len)
{
	char *new_str;
	char *str_end;
	size_t i;

	i = 0;
	while (str[i])
		i++;
	new_str = ft_substr(str, 0, sub_len);
	str_end = ft_substr(str, sub_len+2, i - sub_len - 2);
	new_str = ft_strjoin_free(new_str, inStr);
	new_str = ft_strjoin_free(new_str, str_end);
	free(str_end);
	return (new_str);
}

int ft_get_str_type(const char *str)
{
	char *find_params;

	find_params = (char *)ft_strchr(str, '%');
	if (*(find_params + 1) == 's')
	{
		
		printf("find: S");
	}
	else if (*(find_params + 1) == 'c')
		printf("find: C");
	return (0);
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
		if (final_str[i] == 'c' && final_str[i - 1] == '%')
		{
			char *s;
			char c = va_arg(args, int);
			
			s = ft_strdup(&c);
			printf("char: %c str:%s", c, s);
			ft_insert_strS(final_str, s,i - 1);
		}
		else if (final_str[i] == 's' && final_str[i - 1] == '%')
		{
			char *s = va_arg(args, char *);
			final_str = ft_insert_strS(final_str, s, i - 1);
		}
	
		i++;
	}
	va_end(args);
	ft_print_str(final_str);
	return (0);
}

#include <stdio.h>

int main()
{
	char *str;
	str = "Hello world",

	// ft_printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	ft_printf("str here: %s ce%cto %s\n", str, 'r',"sou teste");
	// printf("\nprintf:\n");
	// printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	// printf("printf: %s %c %d %s\n", "hello", 'l', 3, "teste");
		// printf("printf: %s %c %d %s\n", "hello", 3, "teste", 'l');
	return (0);
}
