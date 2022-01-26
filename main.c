#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char *buffer;

	
	if (argc <= 0)
		return (1);
	
	fd = open(argv[1], O_WRONLY | O_APPEND);
	if (fd < 0)
		return (1);
	else
	{

		printf("argc = %d and argv(1) = %s\n", argc, argv[1]);

		printf("gnl = %d\n", get_next_line(fd, &buffer));
		printf("buffer = %s\n", buffer);	
	}


	(void)fd;
	(void)ret;
	(void)buffer;
	return (0);
}

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
// ./a.out