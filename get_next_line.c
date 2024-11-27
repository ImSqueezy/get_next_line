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

char	*init(int fd, char *tmp, char *s)
{
	ssize_t	i;
	char	*store;
	
	store = NULL;
	i = 1;
	while ((i = read(fd, tmp, BUFFER_SIZE)))
	{
		if (i < 0) // free allocated memory if read fails to read
		{
			perror("read:");
			tmp = NULL;
			return (free(tmp), NULL);
		}
		else if (i == 0)
			break ;
		// printf("tmp %s\n", tmp);
		// printf("store %s\n", store);
		s = tmp;
		printf("%s\n", s);
		store = ft_strjoin(store, s);
		// store = NULL
	}
	// printf("store %s", store);
	return (store);
}

char	*gnl(int fd)
{
    static char *st;
    char *p;
	char *line;

    p = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (!p)
        return (0);
	line = init(fd, p, st);
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