#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another.
 *
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: cp file_from file_to\n");
		exit(1); /* Exit with error code 1 */
	}
	int src = open(argv[1], O_RDONLY);

	if (src == -1)
	{
		perror("Error opening source file");
		exit(2); /* Exit with error code 2 */
	}
	int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (dest == -1)
	{
		perror("Error opening destination file");
		exit(3); /* Exit with error code 3 */
	}
	char buffer[1024]; /* Buffer to hold data */
	ssize_t n_read;    /* Number of bytes read from source file */
	ssize_t n_written; /* Number of bytes written to destination file */

	while ((n_read = read(src, buffer, sizeof(buffer))) > 0)
	{
		n_written = write(dest, buffer, n_read);
		if (n_written != n_read)
		{
			perror("Error writing to destination file");
			exit(4); /* Exit with error code 4 */
		}
	}
	if (n_read == -1)
	{
		perror("Error reading from source file");
		exit(5); /* Exit with error code 5 */
	}

	if (close(src) == -1)
	{
		perror("Error closing source file");
		exit(6); /* Exit with error code 6 */
	}
	if (close(dest) == -1)
	{
		perror("Error closing destination file");
		exit(7); /* Exit with error code 7 */
	}
	return (0); /* Exit with success status */
}
