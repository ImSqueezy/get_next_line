/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:04:39 by aouaalla          #+#    #+#             */
/*   Updated: 2024/12/02 15:08:02 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <errno.h>

static void	clear(char *p)
{
	free(p);
	p = NULL;
}

static char	*init(int fd, char *s, char *buffer)
{
	char	*tmp;
	size_t	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			clear(buffer);
			return (buffer);
		}
		buffer[i] = '\0';
		tmp = s;
		s = ft_strjoin(tmp, buffer);
		clear(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (s);
}

static char	*before_nline(char *str)
{
	size_t	len;

	len = 0;
	if (*str == 10)
		return (ft_substr(str, 0, 1));
	while (str[len] && str[len] != 10)
		len++;
	if (str[len] == 10)
		len++;
	if (len == 0)
		return (0);
	return (ft_substr(str, 0, len));
}

static char	*after_nline(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '\n');
	if (!tmp)
		return (tmp);
	tmp++;
	if (*tmp == '\0')
		return (ft_strdup(tmp));
	return (ft_strdup(tmp));
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*p;
	char		*container;
	char		*line;

	p = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (clear(st), st);
	p = (char *)malloc(((size_t)(BUFFER_SIZE + 1)) * sizeof(char));
	if (!p)
		return (p);
	container = init(fd, st, p);
	st = after_nline(container);
	line = before_nline(container);
	clear(p);
	clear(container);
	return (line);
}

