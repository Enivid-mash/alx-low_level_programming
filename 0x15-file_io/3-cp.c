#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another.
 * @argc: argument count
 * @argv: arguments
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(1);
	}
	int src = open(argv[1], O_RDONLY);

	if (src == -1)
	{
		dprintf(STDERR_FILENO, "Error opening source file\n");
		exit(2);
	}
	int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (dest == -1)
	{
		dprintf(STDERR_FILENO, "Error opening destination file\n");
		exit(3);
	}
	char buffer[1024];
	ssize_t n_read, ssize_t n_written;

	while ((n_read = read(src, buffer, sizeof(buffer))) > 0)
	{
		n_written = write(dest, buffer, n_read);
		if (n_written != n_read)
		{
			dprintf(STDERR_FILENO, "Error writing to destination file\n");
			exit(4);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error reading from source file\n");
		exit(5);
	}
	if (close(src) == -1)
	{
		dprintf(STDERR_FILENO, "Error closing source file\n");
		exit(6);
	}
	if (close(dest) == -1)
	{
		dprintf(STDERR_FILENO, "Error closing destination file\n");
		exit(7);
	}
	return (0);
}

