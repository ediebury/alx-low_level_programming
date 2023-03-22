#include <stdio.h>
#include "3-calc.h"

/**
  *get_op_func - A function that gets operator.
  *@s: A string specifying type of operation.
  *Return: Returns operator function.
  */
int (*get_op_func(char *s)) (int, int)
{
	op_t ops[] = {
	{"+", op_add},
	{"-", op_sub},
	{"*", op_mul},
	{"/", op_div},
	{"%", op_mod},
	{NULL, NULL}
	};

	int i;

	i = 0;

	while (i < 5)
	{
		if (*ops[i].op == *s)
		{
			return (*ops[i].f);
		}
		else
		{
			++i;
		}
	}
	return (NULL);
}
