#include "ft_printf.h"
#include <stdio.h>

// char *ft_strjoin_free(char *s1, char const *s2);

void ft_putnbr(char n)
{
	write(1, &n, 1);
}

void print_nbr(char *ist_str, int nbr, char *base, unsigned int base_len)
{
	unsigned int nbr2;
	size_t str_len;

	str_len = ft_strlen(ist_str);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr2 = (unsigned int)(nbr * -1);
	}
	else
		nbr2 = (unsigned int)(nbr);
	if (nbr2 < base_len)
		ist_str[str_len] = base[nbr2];
	else
	{
		print_nbr(ist_str, nbr2 / base_len, base, base_len);
		print_nbr(ist_str, nbr2 % base_len, base, base_len);
	}
}

char *ft_convert_x(char *str, unsigned int unbr, size_t ist_start)
{
	char *ist_str;
	int i;

	ist_str = ft_calloc(1, sizeof(char));
	print_nbr(ist_str, unbr, "0123456789abcdef", 16);
	i = 0;
	
	return (ft_insert_str_s(str, ist_str, ist_start));
}

// #include <stdio.h>
// int main()
// {
// 	printf("teste: %s\n",ft_convert_x(2555212));
// 	return (0);
// }
