/**
 * _memset - fills memory with a constant byte
 *
 * @s: pointer to character
 *
 * @b: constant byte referred to
 *
 * @n: no. of bytes of memory area pointed to
 *
 * Return: pointer to the memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	for (; n > 0;)
	{
		*(s + --n) = b;
	}
	return (s);
}
