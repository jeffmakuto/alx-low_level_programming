#include <stdio.h>
#include <stdlib.h>

/**
 * change - Calculates the minimum number of coins
 * needed to make change for an amount of money.
 *
 * @cents: The amount of money in cents.
 *
 * Return: The minimum number of coins.
 */
int change(int cents)
{
	int coins = 0;

	if (cents < 0)
	{
		return (0);
	}


	while (cents >= 25)
	{
		cents -= 25;
		coins++;
	}

	while (cents >= 10)
	{
		cents -= 10;
		coins++;
	}

	while (cents >= 5)
	{
		cents -= 5;
		coins++;
	}

	while (cents >= 2)
	{
		cents -= 2;
		coins++;
	}

	while (cents >= 1)
	{
		cents -= 1;
		coins++;
	}

	return (coins);
}

/**
 * main - Entry point. Calculates the minimum number of coins
 * needed to make change for an amount of money.
 *
 * @argc: The number of arguments passed to the program.
 *
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if the program ran successfully, otherwise 1.
 */
int main(int argc, char **argv)
{
	int cents, coins;


	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}


	cents = atoi(argv[1]);


	coins = change(cents);


	printf("%d\n", coins);

	return (0);
}

