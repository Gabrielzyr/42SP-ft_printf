
#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(const char *, ...);
int	ft_convert_c(va_list args);
int ft_convert_d_i(va_list args);
int ft_convert_x(unsigned int unbr, char c);
int ft_convert_p(size_t unbr);
int ft_convert_s(char *print_str);
char *ft_itoa(int n);
char *ft_strchr(const char *s, int c);
int ft_toupper(int c);

// char *ft_insert_str_s(char *str, char *in_str, size_t sub_len);
// char *ft_strjoin_free(char *s1, const char *s2);
// char *ft_insert_str_s_free(char *str, char **in_str, size_t sub_len);
// char *ft_substr(char const *s, unsigned int start, size_t len);

// void *ft_calloc(size_t nmemb, size_t size);
// size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
// char *ft_strjoin(char const *s1, char const *s2);
// char *ft_strdup(const char *s);

#endif