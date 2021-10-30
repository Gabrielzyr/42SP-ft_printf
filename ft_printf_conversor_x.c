#include "ft_printf.h"
#include <stdio.h>

// char *ft_strjoin_free(char *s1, char const *s2);

void ft_putnbr(char n)
{
	write(1, &n, 1);
}

void print_nbr(char *ist_str, int nbr, char *base, size_t base_len)
{
	size_t nbr2;
	size_t str_len;

	str_len = ft_strlen(ist_str);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr2 = (size_t)(nbr * -1);
	}
	else
		nbr2 = (size_t)(nbr);
	if (nbr2 < base_len)
		ist_str[str_len] = base[nbr2];
	else
	{
		print_nbr(ist_str, nbr2 / base_len, base, base_len);
		print_nbr(ist_str, nbr2 % base_len, base, base_len);
	}
}

int ft_convert_x(unsigned int unbr, char c)
{
	char *ist_str;
	size_t length;

	length = 0;
	ist_str = ft_calloc(2, sizeof(char));
	if (c == 'x')
		print_nbr(ist_str, unbr, "0123456789abcdef", 16);
	else
		print_nbr(ist_str, unbr, "0123456789ABCDEF", 16);
	ft_putstr_fd(ist_str, 1);
	length = ft_strlen(ist_str);
	free(ist_str);
	return (length);
}

int ft_convert_p(size_t unbr)
{
	char *ist_str;
	size_t length;

	length = 0;
	ist_str = ft_calloc(2, sizeof(char));
	print_nbr(ist_str, unbr, "0123456789abcdef", 16);
	length = ft_strlen(ist_str);
	if (length == 0)
	{
		free(ist_str);
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(ist_str, 1);
	free(ist_str);
	return (length+2);
}

// int ft_convert_X(char *str, unsigned int unbr, size_t ist_start)
// {
// 	char *ist_str;
// 	size_t length;

// 	ist_str = ft_calloc(2, sizeof(char));
// 	print_nbr(ist_str, unbr, "0123456789abcdef", 16);
// 	length = 0;
// 	while (ist_str[length])
// 	{
// 		ist_str[length] = ft_toupper(ist_str[length]);
// 		length++;
// 	}
// 	ft_putstr_fd(ist_str, 1);
// 	length = ft_strlen(ist_start);
// 	free(ist_str);
// 	return (length);
// }

	// while (ist_str[i])
	// {
	// 	ist_str[i] = ft_toupper(ist_str[i]);
	// 	i++;
	// }
	// printf("teste: %s\n", ist_str);