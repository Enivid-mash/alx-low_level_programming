#include <stdio.h>
#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - initalze a variable of type struct dog
 * @d: First parameter
 * @name: Second parameter
 * @age: Third parameter
 * @owner: Fourth parameter
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
		d = malloc(sizeof(struct dog));
	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
