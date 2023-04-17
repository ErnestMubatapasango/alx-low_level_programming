#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int nt, tl, i;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	for (nt = 0; name[nt]; nt++)
		;
	nt++;
	dog->name = malloc(nt * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; i < nt; i++)
		dog->name[i] = name[i];
	dog->age = age;
	for (tl = 0; owner[tl]; tl++)
		;
	tl++;
	dog->owner = malloc(tl * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	for (i = 0; i < tl; i++)
		dog->owner[i] = owner[i];
	return (dog);
}
