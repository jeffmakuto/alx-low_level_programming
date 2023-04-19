#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - find the required operation function
 * @s: operation string to find its function
 *
 * Return: pointer to operation function that takes to int params
 * otherwith returns NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op && s)
	{
		if (!strcmp(ops[i].op, s))
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
