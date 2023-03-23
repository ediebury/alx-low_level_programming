#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
  * print_numbers - A function that prints numbers, followed by a new line.
  *@separator: String to be printed between numbers.
  *@n : Number of integers passed to the function.
  *
  * Return: No return value.
  */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nums;
	int i, count;

	count = n;

	va_start(nums, n);

	for (i = 0; i < count; i++)
	{
	printf("%d", va_arg(nums, int));

			if (separator != NULL && i < count - 1)
			printf("%s", separator);

	}

	printf("\n");

	va_end(nums);

}
