#include "main.h"

/**
 * generatePassword - Generate a random password.
 *
 * @password: Pointer to the character array where the password will be stored.
 *
 * Return: Void
 */
void generatePassword(char *password)
{
	unsigned int mask = 0, randomBit;
	int i;

	mask |= (1 << 1);   /* Include lowercase letters */
	mask |= (1 << 5);   /* Include uppercase letters */
	mask |= (1 << 10);  /* Include digits */

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		randomBit = rand() % 32; /* Generate a random bit position (0-31) */
		password[i] = 'A' + (randomBit & mask);
	}

	password[PASSWORD_LENGTH] = '\0';
}

/**
 * main - Entry point of the program.
 *
 * This function generates a random password and saves it to a file
 * named "101-password".
 *
 * Return: 0 on success, otherwise 1.
 */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];
	FILE *file;

	srand(time(NULL));  /* Seed the random number generator */
	generatePassword(password);
	file = fopen("101-password", "w");

	if (!file)
	{
		perror("Unable to open the file");
		return (1);
	}

	fprintf(file, "%s", password);
	fclose(file);

	printf("Password generated and saved to file.\n");

	return (0);
}

