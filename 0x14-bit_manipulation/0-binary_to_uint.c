#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 *
 * @b: binary number as a string
 *
 * Return: the converted number, or 0 if:
 *  - b is NULL
 *  - b contains a non-binary digit
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int place = 1;
	int i, len;

	if (b == NULL)
		return (0);

	len = 0;
	while (b[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] == '0')
		{
			place <<= 1;
		}
		else if (b[i] == '1')
		{
			result += place;
			place <<= 1;
		}
		else
		{
			return (0);
		}
	}

	return (result);
}

