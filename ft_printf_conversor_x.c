#include "ft_printf.h"

void ft_putnbr(char n)
{
	write(1, &n, 1);
}

void print_nbr(unsigned int nbr, char *base, unsigned int base_len)
{
	unsigned int nbr2;

	nbr2 = (unsigned int)(nbr);
	if (nbr2 < base_len)
		write(1, &base[nbr2], 1);
	else
	{
		print_nbr(nbr2 / base_len, base, base_len);
		print_nbr(nbr2 % base_len, base, base_len);
	}
}

int ft_convert_x(unsigned int unbr, char c)
{
	size_t length;

	length = 0;
	if (c == 'x')
		print_nbr(unbr, "0123456789abcdef", 16);
	else
		print_nbr(unbr, "0123456789ABCDEF", 16);
	if (unbr == 0)
		return (1);
	while (unbr)
	{
		unbr = unbr / 16;
		length++;
	}
	return (length);
}

void print_nbr_p(size_t nbr, char *base, size_t base_len)
{
	size_t nbr2;

	nbr2 = (size_t)(nbr);
	// printf(nbr)
	if (nbr2 < base_len)
		write(1, &base[nbr2], 1);
	else
	{
		print_nbr_p( nbr2 / base_len, base, base_len);
		print_nbr_p( nbr2 % base_len, base, base_len);
	}
}

int ft_convert_p(size_t unbr)
{
	size_t length;

	ft_putstr_fd("0x", 1);
	if (!unbr)
	{
		write(1, "0", 1);
		return (3);
	}
	print_nbr_p( unbr, "0123456789abcdef", 16);
	length  = 0;
	while (unbr)
	{
		unbr = unbr / 16;
		length++;
	}
	length += 2;
	return (length);
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