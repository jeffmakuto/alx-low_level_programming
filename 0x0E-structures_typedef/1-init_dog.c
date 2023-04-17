#include <stdio.h>
#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 *
 * @d: pointer to the struct to initialize
 *
 * @name: first element
 *
 * @age: second element
 *
 * @owner: third element
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL) /* Check if the pointer is NULL */

		return;

	/* Assign the provided values to the struct members */
	d->name = name;
	d->age = age;
	d->owner = owner;
}
