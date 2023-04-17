#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a struct representing a dog
 *
 * @name: the name of the dog
 *
 * @age: the age of the dog
 *
 * @owner: the owner of the dog
 *
 * Description: This struct represents a dog and its attributes.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - prints a dog struct
 */
void print_dog(struct dog *d)

#endif /* DOG_H */

