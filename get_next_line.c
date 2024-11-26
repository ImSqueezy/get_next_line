#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*init(char *s, char *b, int i)
{
	char	*tmp;
	ssize_t	rv;

	rv = 1;
	while (rv)
	{
		rv = read(fd, b, BUFFER_SIZE);
		if (rv == -1)
		{
			free(s);
			s = NULL;
			return (NULL);
		}
		else if (rv == 0)
			s = ft_strdup("");
		tmp = s;

	}
}


char *get_next_line(int fd)
{
	static char *st;
	char		*p;
	char		*line_read;

	free(st);
	p = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE < 0) // if buffer size = 0 it's going to be handled inside the loop in init
	{
		free(p);
		p = NULL;
		return (NULL);
	}
	if (!p)
		return (NULL);
	line_read = init(s, p, fd);
	return (p);
}

int main()
{
	int fd;
	fd = open("txt.txt", O_RDWR	| O_CREAT, 00644);
	if (fd < 0)
	{
		perror("open:");
		return (0);
	}
	int i;
	i = write(fd, "hello world", 11);
	if (i < 0)
	{
		perror("write:");
		return (0);
	}
	char *p = get_next_line(fd);
	printf("%s", p);
	return (0);
}

// int main()
// {
// 	char *p;
// 	int fd = open("test.txt", O_RDONLY | O_CREAT, 00700 | 00040 | 00004);

// 	int i =  read(fd, p, 5);
// 	p = get_next_line(fd);
// 	printf("%d\n%s", i, p);
// 	return (0);
// }