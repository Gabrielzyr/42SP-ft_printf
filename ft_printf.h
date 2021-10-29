
#ifndef LIBFT_H
#define LIBFT_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

char *ft_convertC(char *str, va_list args, size_t istStart);
char *ft_insert_strS(char *str, char *inStr, size_t sub_len);
char *ft_itoa(int n);
int ft_printf(const char *, ...);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);

void *ft_calloc(size_t nmemb, size_t size);
size_t ft_strlen(const char *s);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);

#endif