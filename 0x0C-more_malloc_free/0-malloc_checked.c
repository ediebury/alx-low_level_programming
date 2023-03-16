#include <stdlib.h>

/**
*malloc_checked - returns a pointer to allocated memory
*
*@b: unsigned integer
*Return: nothing
*/

void *malloc_checked(unsigned int b)
{
	int *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	else
		return (ptr);
}
