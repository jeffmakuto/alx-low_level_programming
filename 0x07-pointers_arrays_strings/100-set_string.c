/**
 * set_string - sets the value of a pointer to a char
 *
 * @s: pointer the pointer of type char
 *
 * @to: pointer to be set to @s
 *
 * return: Void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
