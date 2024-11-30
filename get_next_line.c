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
	char	*p;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] && str[len] != 10)
		len++;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

static char	*after_nline(char *str)
{
	char	*p;
	size_t	len;
	size_t	i;

	while (*str != 10 && *str)
		str++;
	str++;
	len = 0;
	while (str[len])
		len++;
	if (!len)
		return (ft_strdup(""));
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (p);
	i = 0;
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*p;
	char		*container;
	char		*line;

	p = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (clear(st), st);
	p = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!p)
		return (0);
	container = init(fd, st, p);
	st = after_nline(container);
	line = before_nline(container);
	clear(p);
	clear(container);
	return (line);
}
