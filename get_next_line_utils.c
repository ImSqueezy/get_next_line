#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (*str++)
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
	char	*p;
    size_t   i;

	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (0);
    i = 0;
	while (*str)
		p[i++] = *str++;
	p[i] = '\0';
	return (p);
}
