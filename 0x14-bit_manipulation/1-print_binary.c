#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 *
 * @n: decimal number to convert to binary
 *
 * Return: Void
 */
void print_binary(unsigned long int n)
{
	int i, j, binary[32];

	if (n == 0)
	{
		putChar('0');
		return;
	}

	i = 0;

	while (n > 0)
	{
		binary[i] = n % 2; /* Store the remainder (0 or 1) in the binary array */
		n = n / 2; /* Update n by dividing it by 2 */
		i++;
	}

	for (j = i - 1; j >= 0; j--)
		putChar(binary[j] + '0'); /* Print the binary in reverse order */
}
