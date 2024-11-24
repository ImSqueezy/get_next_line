#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

static void	init(char *p, int fd)
{
	// while ()
	read(fd, p, BUFFER_SIZE);
	p[BUFFER_SIZE] = '\0';
}

char *get_next_line(int fd)
{
	char	*p;

	if (fd < 0)
		return (0);
	p = (char *)malloc(BUFFER_SIZE + 1); // allocating for what to be read
										// + the null char (multiply on size of char)
	if (!p)
		return (0);
	init(p, fd); // function to initialize the pointer with what have been red
	return (p);
}

int main()
{
	char *p;
	int fd = open("test.txt", O_RDONLY);

	p = get_next_line(fd);
	printf("%s", p);
	return (0);
}