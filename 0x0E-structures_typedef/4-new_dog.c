#include <stdio.h>
#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - creates a new dog
 *
 * @name: name of the new dog
 *
 * @age: age of the new dog
 *
 * @owner: owner of the new dog
 *
 * Return: dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));

	/* if the function fails */
	if (!dog)
		return (NULL);
	dog->name = malloc(strlen(name) + 1);
	dog->owner = malloc(strlen(owner) + 1);

	if (!dog->name || !dog->owner)
	{
		free(dog->name);
		free(dog->owner);
		free(dog);
		return (NULL);
	}
	/* copy name and owner strings to the new memory locations */
	strcpy(dog->name, name);
	strcpy(dog->owner, owner);

	/* set the age field */
	dog->age = age;

	return (dog);
}
