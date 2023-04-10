#include <stdio.h>
#include <stdlib.h>

/**
 * add_numbers - Adds all positive numbers passed in the command line
 *
 * @argc: The number of arguments passed to the program
 *
 * @argv: An array of pointers to the arguments passed to the program
 *
 * Return: The sum of all positive numbers passed in the command line,
 * or 0 if no numbers were passed or an error occurred.
 */
int add_numbers(int argc, char **argv)
{
	int sum = 0;
	int i, j;

	for (i = 1; i < argc; i++)
	{

		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(1);
			}
		}


		sum += atoi(argv[i]);
	}

	return (sum);
}


/**
 * main - prints sum of all arguments
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
	int sum;

	sum = add_numbers(argc, argv);

	printf("%d\n", sum);

	return (0);
}
