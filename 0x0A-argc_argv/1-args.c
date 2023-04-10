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
int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
