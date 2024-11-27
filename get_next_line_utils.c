/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:37:36 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/27 10:37:58 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return (s1);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc((total_len + 1) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (i < j)
		p[i++] = *s1++;
	j = 0;
	while (i < total_len)
	{
		p[i] = s2[j++];
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t  ft_strlen(const char *str)
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

// int main()
// {
// 	char *store;
// 	int i = 0;
// 	while (i < 2)
// 	{
// 		store = "1234";
// 		store = ft_strjoin(store, "5678");
// 		i++;
// 	}
// 	printf("%s\n", store);
// 	return (0);
// }