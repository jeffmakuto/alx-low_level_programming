#include "main.h"
#include <string.h>

/**
 * is_palindrome_helper - checks if s[i...j] is a
 * palindrome
 *
 * @s: string being checked
 * @i: starting point of the string
 * @j: endpoint of the string
 *
 * Return: 1 if a palindrome and 0 otherwise
 */
int is_palindrome_helper(char *s, int i, int j)
{
	if (i >= j)
	{
		return (1);
	}
	else if (*(s + i) != *(s + j))
	{
		return (0);
	}
	else
	{
		return (is_palindrome_helper(s, i + 1, j - 1));
	}
}

/**
 * is_palindrome - check if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if a palindrome and 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	return (is_palindrome_helper(s, 0, len - 1));
}

