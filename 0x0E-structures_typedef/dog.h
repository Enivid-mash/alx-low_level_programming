#ifndef MAIN_H_
#define MAIN_H_

/**
 * struct dog - Short description
 * @name: First member
 * @age: Second member
 * @owner: Third member
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};


void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
