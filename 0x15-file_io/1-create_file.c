#include "main.h"

/**
 * create_file - creates a file
 *
 * @filename: pointer to filename to create
 *
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 *
 * Description: If the file already exists, its contents are truncated.
 *              If @filename is NULL, returns -1.
 *              If @text_content is NULL, creates an empty file.
 *              The file's permissions are set to rw-------.
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t bytes_written, text_len = 0;
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (*(text_content + text_len) != '\0')
		{
			text_len++;
		}

		bytes_written = write(fd, text_content, text_len);

		if (bytes_written == -1)
		{
			close(fd);

			return (-1);
		}
	}

	close(fd);

	return (1);
}
