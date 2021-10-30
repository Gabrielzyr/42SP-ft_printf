#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char *str;
	int length = 0;
	int length2 = 0;

	str = "Hello world";

	// ft_printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	// ft_printf("str here: %s ce%cto %d %s\n", str, 'r', 54321, "sou teste");
	// length = ft_printf("ftptf: %x\n", 2221314);

	// 	length = ft_printf("%X str %% %x here: %s ce%cto %d %i%s o p está aqui %p\n", 2221314, 2221314, str, 'r', 54321, 231, "sou teste", str);
	// length2 = printf("%X str %% %x here: %s ce%cto %d %i%s o p está aqui %p\n", 2221314, 2221314, str, 'r', 54321, 231, "sou teste", str);

	length = printf("1ptf aqui: %p\n", -1);
	length2 = ft_printf("fptf aqui: %p\n", -1);
	printf("\nlength: %d | length2: %d\n", length, length2);
	// printf("ptf: %x\n", 2221314);
	// printf()
	// printf("teste: %x\n", 22324541);
	// ft_printf("str here: ce %c to\n",'r');
	// printf("\nprintf:\n");
	// printf("str here: %s | schar: %c %s %c", str, 'A', "opa", 'a');
	// printf("printf: %s %c %d %s\n", "hello", 'l', 3, "teste");
	// printf("printf: %s %c %d %s\n", "hello", 3, "teste", 'l');
	return (0);
}
