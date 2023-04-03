/**
 * _strspn - gets the lenth of a prefix substring
 *
 * @s: string to search
 *
 * @accept: bytes to accept
 *
 * Return: the no. of bytes in initial segment of @s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				break;
			}

		}
		if (*(accept + j) == '\0')
		{
			break;
		}

	}
	return (i);
}
