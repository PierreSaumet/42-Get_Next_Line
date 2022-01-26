#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	int ret;
	char *buffer;

	buffer = NULL;
	fd = 0;
	ret = 0;
	if (argc <= 0)
		return (1);
	else
	{
		// testing wrong fd, should return -1
		printf("fd = %d GNL_ret = %d and buff = %s\n", -5, get_next_line(-5, &buffer), buffer);
		printf("fd = %d GNL_ret = %d and buff = %s\n", -50, get_next_line(-50, &buffer), buffer);
		printf("fd = %d GNL_ret = %d and buff = %s\n", 3, get_next_line(3, &buffer), buffer);
		printf("fd = %d GNL_ret = %d and buff = %s\n", 1250834982, get_next_line(1250834982, &buffer), buffer);
		printf("fd = %d GNL_ret = %d and buff = %s\n", 612985234, get_next_line(612985234, &buffer), buffer);
	}
	
	/*
	fd = open(argv[1], O_WRONLY | O_APPEND);
	if (fd < 0)
		return (1);
	else
	{

		printf("argc = %d and argv(1) = %s\n", argc, argv[1]);

		printf("gnl = %d\n", get_next_line(fd, &buffer));
		printf("buffer = %s\n", buffer);	
	}
	*/

	(void)fd;
	(void)ret;
	(void)buffer;
	(void)argc;
	(void)argv;
	return (0);
}

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
// ./a.out