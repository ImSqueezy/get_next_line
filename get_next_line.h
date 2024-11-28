#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 6
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h> // temporarly

char	*get_next_line(int fd);
char    *ft_strdup(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif