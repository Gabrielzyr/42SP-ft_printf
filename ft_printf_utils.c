#include "ft_printf.h"
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

char *ft_insert_str_s(char *str, char *in_str, size_t sub_len)
{
	char *new_str;
	char *str_end;
	size_t i;

	i = 0;
	while (str[i])
		i++;
	new_str = ft_substr(str, 0, sub_len);
	str_end = ft_substr(str, sub_len + 2, i - sub_len - 2);
	new_str = ft_strjoin_free(new_str, in_str);
	new_str = ft_strjoin_free(new_str, str_end);
	// free(in_str);
	free(str_end);
	return (new_str);
}

// char *ft_insert_str_s_free(char *str, char **in_str, size_t sub_len)
// {
// 	char *new_str;
// 	char *str_end;
// 	size_t i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	new_str = ft_substr(str, 0, sub_len);
// 	str_end = ft_substr(str, sub_len + 2, i - sub_len - 2);
// 	new_str = ft_strjoin_free(new_str, *in_str);
// 	new_str = ft_strjoin_free(new_str, str_end);
// 	free(in_str);
// 	free(str_end);
// 	return (new_str);
// }