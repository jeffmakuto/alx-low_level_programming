#include "main.h"

/**
 * close_all - closes all opened file streams with error handling
 *
 * @count: the number of passed file descriptors
 *
 * Return: Void
 */
void close_all(int count, ...)
{
	va_list ap;

	va_start(ap, count);
	for (; count > 0; count--)
	{
		int fd = va_arg(ap, int);

		if (close(fd))
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(CLOSE_FAIL_STATUS);
		}
	}
	va_end(ap);
}

/**
 * copy_content - copies content from @fd_src to @fd_dest file descriptors
 *
 * @fd_dest: the file descriptor of the destination file
 *
 * @fd_src: the file descriptor of the source file
 *
 * @file_dest: the destination file name
 *
 * @file_src: the source file name
 *
 * Return: Void
 */
void copy_content(int fd_dest, int fd_src, char *file_src, char *file_dest)
{
	char buffer[BUFFER_SIZE];
	int bytesRead;

	do {
		memset(buffer, 0, BUFFER_SIZE);
		bytesRead = read(fd_src, buffer, BUFFER_SIZE);
		if (bytesRead < 0)
		{
			dprintf(STDERR_FILENO, "Can't read from file %s\n", file_src);
			exit(READ_FAIL_STATUS);
		}
		if (fd_dest < 0 || write(fd_dest, buffer, bytesRead) < 0)
		{
			close_all(1, fd_src);
			dprintf(STDERR_FILENO, "Can't write to %s\n", file_dest);
			exit(WRITE_FAIL_STATUS);
		}
	} while (bytesRead > 0);
}

/**
 * main - a program to copy content of file to another one
 *
 * @argc: number of arguments
 *
 * @argv: passed arguments as cstring array
 *
 * Description:
 * arguments must to be <file_from> <file_to>
 *
 * Return: status code 0 on success,
 * returns 97 on invalid args,
 * if can not read from <file_from> returns 98
 */
int main(int argc, char **argv)
{
	char *file_from, *file_to;
	int fd_from, fd_to;

	/* check args */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(USAGE_STATUS);
	}
	file_from = argv[1];
	file_to = argv[2];

	/* open src file */
	fd_from = open(file_from, O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(READ_FAIL_STATUS);
	}

	/* open dest file */
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, WFILE_MODE);
	/* copy content */
	copy_content(fd_to, fd_from, file_from, file_to);

	/* close and clean */
	close_all(2, fd_to, fd_from);
	return (0);
}
