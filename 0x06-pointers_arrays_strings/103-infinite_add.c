#include <stdio.h>
#include <string.h>

/**
 * strshiftl - shift string to left @n characters
 * @str: the string reference
 * @size: the size of selected string buffer to shift
 * @n: the number of left shifts
 * Description:
 * shift @size characters of @str @n times to left
 * with null characters right padding
 * and a null character at the end (index: @size + @steps)
 */
void strshiftl(char *str, int size, int n)
{

	*(str + size + n) = 0;
	for (; size > 0; size--)
		*(str + size + n - 1) = *(str + size - 1);

	for (; n > 0; n--)
		*(str + n - 1) = 0;
}

/**
 * infinite_add - sum 2 strings as numbers
 * @n1: the reference to 1st string
 * @n2: the reference to 2nd string
 * @r: the reference to the result string
 * @size_r: the allocated size for the result string (@r)
 * Return: a pointer to the result string (@r) or Null on fail
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, asize, bsize, msize;
	char c1, c2, cu = 0;

	asize = strlen(n1);
	bsize = strlen(n2);
	msize = asize > bsize ? asize : bsize;
	if (msize > size_r - 1)
		return (NULL);

	for (i = 1; i <= msize; i++)
	{
		int over = 0;

		c1 = i > asize ? 0 : *(n1 + asize - i) - '0';
		c2 = i > bsize ? 0 : *(n2 + bsize - i) - '0';
		c1 += c2 + cu;
		over = c1 >= 10;
		cu = over ? c1 / 10 : 0;
		if (over)
			c1 %= 10;

		*(r + msize - i) = c1 + '0';
	}

	if (cu && size_r - 1 <= msize)
		return (NULL);

	if (cu && size_r - 1 > msize)
	{
		strshiftl(r, msize, 1);
		*r = cu + '0';
	}

	return (r);
}

