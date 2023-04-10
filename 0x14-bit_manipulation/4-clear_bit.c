#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 *
 * @n: pointer to number to clear bit in
 * @index: index of bit to clear (starting from 0)
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8) /* check if index is valid */
		return (-1);

	*n &= ~(1UL << index); /* clear bit at index */

	return (1); /* return success */
}

