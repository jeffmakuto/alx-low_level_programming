#include <string.h>
#include <stdlib.h>

/**
 * get_total_size - calculates the total size of the concatenated string
 * @ac: number of strings in the array
 * @av: the reference to the array
 * Return: the total size of the concatenated string
 */
int get_total_size(int ac, char **av)
{
	int i, size = 0;

	for (i = 0; i < ac; i++)
	{
		size += strlen(av[i]);
	}

	return (size + ac + 1);
}

/**
 * concat_strings - concatenates each string into the final string
 * @ac: number of strings in the array
 * @av: the reference to the array
 * @str: the pointer to the final string
 */
void concat_strings(int ac, char **av, char *str)
{
	int i, ci, size = 0;

	for (i = 0; i < ac; i++)
	{
		ci = 0;

		while (av[i][ci])
		{
			str[size++] = av[i][ci++];
		}

		str[size++] = '\n';
	}

	str[size] = '\0';
}

/**
 * argstostr - write array of strings into one string
 * @ac: number of strings in the array
 * @av: the reference to the array
 * Return: pointer to the string otherwise NULL
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int total_size;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	total_size = get_total_size(ac, av);

	str = calloc(total_size, sizeof(char));

	if (str == NULL)
	{
		return (NULL);
	}

	concat_strings(ac, av, str);

	return (str);
}

