#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiples two numbers
 *
 * @argc: the number of arguments passed to the program
 *
 * @argv: an array of strings containing the arguments
 * passed to the program
 *
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	int a, b;

	if (argc != 3)
	{
		puts("Error");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d\n", a * b);

	return (0);
}
