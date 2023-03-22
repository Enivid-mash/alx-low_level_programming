#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: Name of the dog
 * @age: age of the dog
 * @owner: owner of the dog.
 *
 * Return: pointer to new dog, otherwis NULL.
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog1;
	int len1, len2, x;

	dog1 = (dog_t *)malloc(sizeof(dog_t));
	if (dog1 == NULL)
		return (NULL);

	len1 = len2 = 0;
	while
		(name[len1++])
	while
		(owner[len2++]);
	(*dog1).name = malloc(len1 * sizeof((*dog1).name));
	if ((*dog1).name == NULL)
	{
		free(dog1);
		return (NULL);
	}
	for (x = 0; x <= len1; x++)
		(*dog1).name[x] = name[x];
	(*dog1).age = age;
	(*dog1).owner = malloc(len2 * sizeof((*dog1).owner));
	if ((*dog1).owner == NULL)
	{
		free((*dog1).name);
		free(dog1);
		return (NULL);
	}
	for (x = 0; x <= len2; x++)
		(*dog1).owner[x] = owner[x];
	return (dog1);
}
