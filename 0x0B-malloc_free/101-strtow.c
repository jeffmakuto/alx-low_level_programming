#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * count_words - counts the number of words in a string
 * @str: string to count words in
 *
 * Return: number of words in str
 */
static int count_words(char *str)
{
	int count = 0;
	char *p = str;

	while (*p != '\0')
	{
		while (isspace(*p))
			++p;

		if (*p != '\0')
		{
			++count;
			while (*p != '\0' && !isspace(*p))
				++p;
		}
	}

	return (count);
}

/**
 * copy_word - copies a word from str into a new string
 * @str: string to copy word from
 * @len: length of word to copy
 *
 * Return: pointer to new string containing word, or NULL on failure
 */
static char *copy_word(char *str, int len)
{
	char *word;

	word = (char *) malloc(len + 1);

	if (word == NULL)
		return (NULL);

	strncpy(word, str, len);
	word[len] = '\0';

	return (word);
}

/**
 * free_words - frees memory used by array of words
 * @words: array of words to free
 */
static void free_words(char **words)
{
	int i = 0;

	while (words[i] != NULL)
	{
		free(words[i]);
		++i;
	}

	free(words);
}

/**
 * split_words - splits a string into an array of words
 * @str: string to split
 * @num_words: number of words in str
 *
 * Return: pointer to an array of strings (words) or NULL if str is NULL,
 * str is empty or if memory allocation fails
 */
static char **split_words(char *str, int num_words)
{
	int i, len;
	char **words, *p, *start, *word;

	words = (char **) malloc(sizeof(char *) * (num_words + 1));

	if (words == NULL)
		return (NULL);

	p = str;
	i = 0;

	while (*p != '\0')
	{
		while (isspace(*p))
			++p;

		if (*p != '\0')
		{

			start = p;

			while (*p != '\0' && !isspace(*p))
				++p;

			len = p - start;
			word = copy_word(start, len);

			if (word == NULL)
			{
				free_words(words);
				return (NULL);
			}

			words[i++] = word;
		}
	}
	words[i] = NULL;
	return (words);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words) or NULL if str is NULL,
 * str is empty or if memory allocation fails
 */
char **strtow(char *str)
{
	int num_words;
	char **words;

	num_words = count_words(str);
	words = split_words(str, num_words);

	return (words);
}

