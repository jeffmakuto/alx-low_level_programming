/**
 * _strcmp - compare @s1 and @s2
 *
 * @s1: the 1st number to compare
 *
 * @s2: the 2nd number to compare
 *
 * Return: 0 if @s1 == @s2
 *
 * positive integer if @s1 > @s2
 *
 * negaitve integer if @s1 < @s2
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
	{
		/* empty */
	}

	return (*s1 - *s2);
}
