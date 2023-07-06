#include "main.h"

/**
 * main - Generate the password for crackme3 and write it to `101-password`.
 *
 * This program generates a password using a specific pattern and saves it
 * to a file named "101-password".
 *
 * Return: 0 on success, otherwise 1.
 */
int main(void)
{
	FILE *fd;
	char password[PASSWORD_LENGTH + 1];

	generatePassword(password);
	fd = fopen("101-password", "w");

	if (!fd)
	{
		perror("Error opening file '101-password'");
		return (1);
	}

	if (fprintf(fd, "%s", password) < 0)
	{
		perror("Error writing to file");
		fclose(fd);
		return (1);
	}

	if (fclose(fd) == EOF)
	{
		perror("Error closing file");
		return (1);
	}

	return (0);
}

/**
 * generatePassword - Generate a password using a specific pattern.
 *
 * @password: Pointer to the character array where the password will be stored.
 *
 * Return: Void
 */
void generatePassword(char *password)
{
	int i;

	for (i = 0; i < PASSWORD_LENGTH; i++)
		password[i] = 0x46c6f48U >> ((i & 3) << 3) & 0xff;
	password[PASSWORD_LENGTH] = '\0';
}

