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
		// testing overflow, compile without -Werror
		printf("fd = %d GNL_ret = %d and buff = %s\n", 2147483647, get_next_line(2147483647, &buffer), buffer);
		printf("fd = %ld GNL_ret = %d and buff = %s\n", -2147483648, get_next_line(-2147483648, &buffer), buffer);
		printf("fd = %ld GNL_ret = %d and buff = %s\n", 2147483648, get_next_line(2147483648, &buffer), buffer);
		printf("fd = %ld GNL_ret = %d and buff = %s\n", -2147483649, get_next_line(-2147483649, &buffer), buffer);
	

		// testing empty file, should return 0
		fd = open("empty.txt", O_RDONLY);
		if (fd < 0)
			return (1);
		ret = get_next_line(fd, &buffer);
		printf("ret = %d, and buffer = %s\n", ret, buffer);
		free(buffer);
		buffer = NULL;
		close(fd);
		// testing a simple read, should display the content of the file
		if (argc == 2)
		{
			fd = open(argv[1], O_RDONLY);
			if (fd < 0)
				return (1);
			ret = get_next_line(fd, &buffer);
			while (ret == 1)
			{
				printf("ret = %d, and buffer = %s\n", ret, buffer);
				free(buffer);
				buffer = NULL;

				ret = get_next_line(fd, &buffer);
			}
			free(buffer);
			close(fd);
		}
		// testing multiple fd
		if (argc == 3)
		{
			fd = open(argv[1], O_RDONLY);
			ret = get_next_line(fd, &buffer);
			printf("ret = %d, and buffer = %s\n", ret, buffer);
			free(buffer);
			buffer = NULL;
			
			int fd2;
			fd2 = open(argv[2], O_RDONLY);
			int ret2;
			ret2 = get_next_line(fd2, &buffer);
			printf("ret2 = %d, and buffer2 = %s\n", ret2, buffer);
			free(buffer);
			buffer = NULL;

			while (ret != 0 || ret2 != 0)
			{
				ret = get_next_line(fd, &buffer);
				printf("ret = %d, and buffer = %s\n", ret, buffer);
				free(buffer);
				buffer = NULL;
				ret2 = get_next_line(fd2, &buffer);
				printf("ret2 = %d, and buffer2 = %s\n", ret2, buffer);
				free(buffer);
				buffer = NULL;
				//ret = get_next_line(fd, &buffer);
			}
			free(buffer);
			buffer = NULL;
			close(fd);
			close(fd2);
		}
	}
	return (0);
}

//cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
// ./a.out

// cc -Wall -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c

// valgrind
// cc -Wall -Wextra -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c && valgrind --leak-check=full ./a.out main.c get_next_line.h
