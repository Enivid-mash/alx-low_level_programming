#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * append_text_to_file - appends text at the end of a file.
 *
 * @filename: file
 * @text_content: content to appends
 *
 * Return: 1 on success otherwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd_o;
	int fd_w;
	int len =  0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd_o = open(filename, O_WRONLY | O_APPEND);

	fd_w = write(fd_o, text_content, len);

	if (fd_o == -1 || fd_w == -1)
		return (-1);

	close(fd_o);

	return (1);
}
