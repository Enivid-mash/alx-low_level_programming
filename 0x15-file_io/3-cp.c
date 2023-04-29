#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void c_file(int fd);
char *c_buff(char *file);


/**
 * c_file - close file
 * @fd: file fd
 **/
void c_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * c_buff - Allocates memory for buff
 * @file: name of file
 *
 * Return: Pointer to allocated memory
 **/
char *c_buff(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buff);
}


/**
 * main - Copies the content of a file fdo_2 another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	int fdo_1, fdo_2;
	int r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = c_buff(argv[2]);
	fdo_1 = open(argv[1], O_RDONLY);
	r = read(fdo_1, buff, 1024);
	fdo_2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fdo_1 == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read to file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(fdo_2, buff, r);
		if (fdo_2 == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(fdo_1, buff, 1024);
		fdo_2 = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(buff);
	c_file(fdo_1);
	c_file(fdo_2);
	return (0);
}
