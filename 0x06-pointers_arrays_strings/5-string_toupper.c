/**
 * string_toupper - change all lowercase letters to uppercase
 *
 * @str: reference to a string
 *
 * Return: @str
 */
char *string_toupper(char *str)
{
	int i;
	char c;

	for (i = 0; (c = *(str + i)); i++)
	{
		if (c >= 'a' && c <= 'z')
		{
			*(str + i) = c - 32;
		}
	}
	return (str);
}
