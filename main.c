#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *str;
	str = "Hello world",

	// ft_printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	// ft_printf("str here: %s ce%cto %d %s\n", str, 'r', 54321, "sou teste");
	ft_printf("ftptf: %x\n", 2221314);
	printf("ptf: %x\n", 2221314);
	// printf("teste: %x\n", 22324541);
	// ft_printf("str here: ce %c to\n",'r');
	// printf("\nprintf:\n");
	// printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	// printf("printf: %s %c %d %s\n", "hello", 'l', 3, "teste");
	// printf("printf: %s %c %d %s\n", "hello", 3, "teste", 'l');
	return (0);
}
