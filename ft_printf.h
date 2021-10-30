
#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

char *ft_strjoin_free(char *s1, const char *s2);
char *ft_convert_c(char *str, va_list args, size_t ist_start);
char *ft_convert_d_i(char *str, va_list args, size_t ist_start);
char *ft_convert_x(char *str, unsigned int unbr, size_t ist_start);
char *ft_insert_str_s(char *str, char *in_str, size_t sub_len);
char *ft_insert_str_s_free(char *str, char **in_str, size_t sub_len);
char *ft_itoa(int n);
int ft_printf(const char *, ...);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);

int ft_toupper(int c);
void *ft_calloc(size_t nmemb, size_t size);
size_t ft_strlen(const char *s);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);

#endif