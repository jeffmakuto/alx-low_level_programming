#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 *
 * @filename: pointer to the file name
 *
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_write, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;

		n_write = write(fd, text_content, len);

		if (n_write == -1 || n_write != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
