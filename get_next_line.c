/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:38:32 by aouaalla          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:39 by aouaalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"


	// if read returned -1 (error occured)
	// if read returned 0 (nothing to read)
	// esle the number of bytes read is returned

// static char *_set_line(char *line_buffer)
// {
//     char    *left_c;
//     ssize_t    i;
    
//     i = 0;
//     while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
//         i++;
//     if (line_buffer[i] == 0 || line_buffer[1] == 0)
//         return (NULL);
//     left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
//     if (*left_c == 0)
//     {
//         free(left_c);
//         left_c = NULL;
//     }    
//     line_buffer[i + 1] = 0;
//     return (left_c);
// }

char	*init(int fd, char *s, char *buffer)
{
	char	*tmp;
	ssize_t	i;

	while ((i = read(fd, buffer, BUFFER_SIZE)))
	{
		// printf("[%d]", i);
		if (i < 0)
		{
			perror("read:");
			buffer = NULL;
			return (free(buffer), buffer);
		}
		buffer[i] = '\0';
		// if (!s)
		// 	s = ft_strdup("");
		tmp = s;
		printf("{%s}", s);
		s = ft_strjoin(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	tmp = NULL;
	return (s);
}


char	*gnl(int fd)
{
    static char *st;
    char *p;
	char *line;

    p = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!p)
        return (0);
	line = init(fd, st, p);
	p = NULL;
	free(p);
	if (!line)
		return (line);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY); // the file containes two lines
	if (fd < 0)
		perror("open:");
	char *p = gnl(fd);
	// printf("%s", p);
	return (0);
}

// return null on read's failure
// return the line read if success (\n included at the end unless no \n found at the end of the file)