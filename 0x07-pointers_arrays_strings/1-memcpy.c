/**
 * _memcpy - copies memory area
 *
 * @n: no. of bytes
 *
 * @src: memory area copied from
 *
 * @dest: memory area copied to
 *
 * Return: a pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
