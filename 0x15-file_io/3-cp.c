#include "main.h"

/**
 * print_error_and_exit - prints the usage message and exits with code 97
 *
 * @exit_code: pointer to the exit code
 *
 * @error_message: pointer to the error message
 *
 */
void print_error_and_exit(int exit_code, const char *error_message)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(exit_code);
}

/**
 * main - entry point
 *
 * @argc: numberof arguments passed
 *
 * @argv: an array of the arguments passed
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	mode_t mode = O_WRONLY | O_CREAT | O_TRUNC;
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
		print_error_and_exit(97, "Usage: cp file_from file_to");

	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
	{
		char error_message[256];

		sprintf(error_message, "Error: Can't read from file %s", argv[1]);
		print_error_and_exit(98, error_message);
	}
	fd_to = open(argv[2], mode, permissions);

	if (fd_to == -1)
	{
		char error_message[256];

		sprintf(error_message, "Error: Can't write to %s", argv[2]);
		print_error_and_exit(99, error_message);
	}
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_error_and_exit(99, "Error: Incomplete write operation");
	}
	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Failed to read from file");
	if (close(fd_from) == -1 || close(fd_to) == -1)
		print_error_and_exit(100, "Error: Can't close file descriptor");
	return (0);
}

