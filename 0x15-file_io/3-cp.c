#include "main.h"

/**
 * main - Copies the content of a file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	char buf[BUFSIZ];
	int i, j, k, fdr, fdw;

	fdr = open(argv[1], O_RDONLY);
	if (fdr < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fdw = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((i = read(fdr, buf, BUFSIZ)) > 0)
	{
		if (fdw < 0 || write(fdw, buf, i) != i)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fdr);
			exit(99);
		}
	}
	if (i < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	j = close(fdr);
	k = close(fdw);
	if (j < 0 || k < 0)
	{
		if (k < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdw);
		if (j < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fdr);
		exit(100);
	}
	return (0);
}
