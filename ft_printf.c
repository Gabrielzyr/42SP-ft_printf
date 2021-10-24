#include "ft_printf.h"

#include <stdio.h>

void ft_print_str(char *str)
{
	size_t i;

	i = 1;
	while (*str++)
		i++;
	write(1, str, i);
}

char ft_insert_strS(char *str, ...)
{
	char *new_str;
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (new_str);
}

int ft_get_str_type(const char *str)
{
	char *find_params;

	find_params = (char *)ft_strchr(str, '%');
	if (*(find_params + 1) == 's')
		printf("find: S");
	else if (*(find_params + 1) == 'c')
		printf("find: C");
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	ft_get_str_type(str);
	va_end(args);
	return (0);
}


#include <stdio.h>

int main()
{
	char *str;
	str = "Hello world",

	ft_printf("str here: %c", str);
	// printf("str here: %s", str);
	return (0);
}
