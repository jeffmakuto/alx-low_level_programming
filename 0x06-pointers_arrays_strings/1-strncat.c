/**
 * _strncat - concatenates strings @dest and @src to @dest with @n bytes limit
 *
 * @dest: the string to append @src to
 *
 * @src: the string to be appended to @dest
 * @n: number of bytes to be copied from @src to @dest
 *
 * Return: pointer to @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *p = dest;

	/* move dest pointer to the end of the string */
	for (; *dest; dest++)
	{
		/* empty */
	}

	/* copy from src to dest */
	for (; *src && n > 0; src++, dest++, n--)
	{
		*dest = *src;
	}

	/* set null char at the new end */
	*dest = 0;

	return (p);
}
