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

#include "get_next_line.h"
#include <stdio.h>

char	*init(int fd, char *s, char *buffer)
{
	char	*tmp;
	ssize_t	i;

	while ((i = read(fd, buffer, BUFFER_SIZE)))
	{
		if (i < 0)
		{
			free(buffer);
			buffer = NULL;
			return (buffer);
		}
		buffer[i] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (s);
}

void	clear(char *p)
{
	free(p);
	p = NULL;
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*p;
	char		*line;

	p = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (clear(st), st);
	p = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (0);
	line = init(fd, st, p);
	clear(p);
	return (line);
}

// code substr
// think about a way to copy whats after the \n and merge it with the new line (process)