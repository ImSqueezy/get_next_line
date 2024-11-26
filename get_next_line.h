#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> // temporarly

char	*get_next_line(int fd);
char    *ft_strdup(char *str);

#endif