#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
  *main - A program that performs simple operations.
  *@argc: Argument count.
  *@argv: Argument vector.
  *Return: 0 on sucessful exit.
  */

int main(int argc, char **argv)
{
	int num1, num2, res;
	char sign;
	char *op;
	int (*ope)(int, int);

	if (argc != 4)
	{
		printf("Error");
		exit(98);
	}

	sign = argv[2][0];

	if ((sign != '+' && sign != '-' && sign != '*' && sign != '/' && sign != '%') || argv[2][1] != '\0')
	{
		printf("Error");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	if (num2 == 0 && (sign == '%' || sign == '/'))
	{
		printf("Error");
		exit(100);
	}

	op = argv[2];
	ope = get_op_func(op);
	res = ope(num1, num2);
	printf("%d\n", res);
	return (0);
	}
