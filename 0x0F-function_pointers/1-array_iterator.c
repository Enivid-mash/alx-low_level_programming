#include "function_pointers.h"

/**
 *array_iterator - executes a function given as a parameter
 *
 *@array: array to execute.
 *@size: size of the array.
 *@action: pointer to the func to use
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array && action)
		while  (size--)
			action(*(array++));
}
