/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:04:39 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/28 14:04:41 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*init(int fd, char *s, char *buffer)
{
	char	*tmp;
	ssize_t	i;

	while ((i = read(fd, buffer, BUFFER_SIZE)))
	{
		if (i < 0)
		{
			perror("read:");
			buffer = NULL;
			return (free(buffer), buffer);
		}
		buffer[i] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	tmp = NULL;
	return (s);
}

char	*get_after_line(char *str)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i += 1;
	p = (char *)malloc(i * sizeof(char));
	j = 0;
	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	return (p);
}

char	*gnl(int fd)
{
	static char	*st;
	char		*p;
	char		*line;

	p = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (0);
	line = init(fd, st, p);
	p = NULL;
	free(p);
	st = get_after_line(line);
	line = NULL;
	return (st);
}
