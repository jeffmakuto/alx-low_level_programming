#include "main.h"
/**
 * leet - encode a string into 1337.
 * @str: the string reference to encode
 * Description:
 * Letters `a` and `A` should be replaced by `4`
 * Letters `e` and `E` should be replaced by `3`
 * Letters `o` and `O` should be replaced by `0`
 * Letters `t` and `T` should be replaced by `7`
 * Letters `l` and `L` should be replaced by `1`
 * Return: @char
 */
char *leet(char *str)
{
	int i, j;
	char s, c;
	char old_c[] = "aeotl";
	char new_c[] = "43071";

	for (i = 0; (s = *(str + i)); i++)
	{
		for (j = 0; (c = old_c[j]); j++)
		{
			if (s == c || s == old_c[j] - 32)
			{
				*(str + i) = new_c[j];
			}
		}
	}
	return (str);
}
