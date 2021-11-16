#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	fd = 0, line_num = 1, limit = argc - 1, i = 1, first_fd, last_fd;
	char	*line;

	while (argc-- > 1)
	{
		if ((fd = open(argv[i++], O_RDONLY)) == -1) 
		{
			printf("file #%d could not be opened\n", i);
			while (fd-- > 2)
				close(fd);
			return (1);
		}
		fd++;
	}
	first_fd = fd - limit;
	last_fd = (first_fd + limit - 1);
	if (fd == 0)
	{
		while ((line = get_next_line(fd, &line)) != NULL)
		{
			printf("fd: %d Line: %d| %s\n", fd, line_num++, line);
			free(line);
		}
	}
	else
	{
		while (limit)
		{
			if (fd >= last_fd)
				fd = first_fd;
			else
				fd++;
			while (line = get_next_line(fd, &line))
			{
				if (!line)
					break ;
				else
				{
					printf("fd: %d Line: %d| %s\n", fd, line_num++, line);
					free(line);
				}
				if (fd >= last_fd)
					fd = first_fd;
				else
					fd++;
			}
			close(fd);
			limit--;
		}
	}
	printf("fd: %d Line: %d| %s\n", fd, line_num++, line);
	free(line);
	close(fd);
	return (0);
}
