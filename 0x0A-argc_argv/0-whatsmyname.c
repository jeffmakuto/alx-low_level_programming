#include <stdio.h>

/**
 * main - prints the name of the program
 *
 * @argc: the number of arguments passed to the program
 *
 * @argv: an array of strings containing the arguments
 * passed to the program
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);

	/* Showing argc is not being used */
	(void)argc;

	return (0);
}

