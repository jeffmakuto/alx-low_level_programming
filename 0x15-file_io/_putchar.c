include "main.h"

/**
 * _putchar - Writes a character to the standard output
 *
 * @c: The character to be written
 *
 * Return: On success, it returns the written character as
 * an unsigned char cast to an int.
 * On failure, it returns EOF (usually -1).
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

