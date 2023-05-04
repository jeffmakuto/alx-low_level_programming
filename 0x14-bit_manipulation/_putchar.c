#include <unistd.h>

/**
 * _putchar - writes the character @c to stdout
 *
 * @c: the character to print
 *
 * Return: 1 on success otherwise -1 and errno is set.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
