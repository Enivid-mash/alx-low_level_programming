#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a file and prints it
 *
 * @filename: pointer to file path
 * @letters: size of bytes to read
 *
 * Return: the actual size of letters read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd_o, fd_r, fd_w;
	char *buffer = malloc(sizeof(char) * letters);

	if (*filename == 0)
		return (0);
	fd_o = open(filename, O_RDONLY);
	fd_r = read(fd_o, buffer, letters);
	if (fd_o == -1 || fd_r == -1)
	{
		free(buffer);
		return (0);
	}
	fd_w = write(STDOUT_FILENO, buffer, fd_r);
	if (fd_w == -1 || fd_r != fd_w)
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	close(fd_o);
	return (fd_r);
}
