#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
  * print_strings - A function that prints strings, followed by a new line.
  *@separator: String to be printed between strings.
  *@n : Number of stringss passed to the function.
  *
  * Return: No return value.
  */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strgs;
	int i, count;
	char *holder;

	count = n;

	va_start(strgs, n);

	for (i = 0; i < count; i++)
	{
		holder = va_arg(strgs, char*);

		printf("%s", holder);

			if (separator != NULL && i < count - 1)
			printf("%s", separator);

	}

	printf("\n");

	va_end(strgs);

}
