#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the reference to the string
 */
void rev_string(char *s)
{
	int len = 0, i, mid;
	char c = *s;

	/* get string lenth */
	while (c != '\0')
	{
		c = *(s + ++len);
	}

	/* end if string lenth is zero */
	if (len == 0)
	{
		return;
	}

	mid = len / 2;

	/* fadi */

	/* reverse string */
	for (i = 0; i < mid; i++)
	{
		char tmp;
		int a = len - i - 1;

		tmp = *(s + i);
		*(s + i) = *(s + a);
		*(s + a) = tmp;
	}
}
