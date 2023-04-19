#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - program that preforms simple operations
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: exit status
 */
int main(int argc, char **argv)
{
	int a, b;
	char *op;
	int (*op_fun)(int, int);

	if (argc != 4)
	{
		puts("Error");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	op = argv[2];
	op_fun = get_op_func(op);

	if (!op_fun)
	{
		puts("Error");
		return (99);
	}

	if ((*op == '/' || *op == '%') && !b)
	{
		puts("Error");
		return (100);
	}

	printf("%d\n", op_fun(a, b));
	return (0);
}
