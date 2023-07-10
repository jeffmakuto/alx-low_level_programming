#include "main.h"

/**
 * create_file - Creates a file with the given name and writes
 * the text content to it.
 *
 * @filename: The name of the file to create.
 *
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		bytes_written = write(fd, text_content, length);
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);


	return (1);
}

