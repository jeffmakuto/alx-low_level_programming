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
int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", *(argv + i));
	}
	
	return (0);
}
