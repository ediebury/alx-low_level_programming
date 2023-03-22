#include <stdio.h>
#include "3-calc.h"

/**
  *op_add - Adds two integers.
  *@a: First integer.
  *@b: Second integer.
  *Return: Sum of the integers.
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  *op_sub - Subtracts first integer from second.
  *@a: First integer.
  *@b: Second integer.
  *Return: Subtraction of the integers.
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  *op_mul - Multiplies two integers.
  *@a: First integer.
  *@b: Second integer.
  *Return: Multiplication of the integers.
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  *op_div - Divides first integer by second.
  *@a: First integer.
  *@b: Second integer.
  *Return: Division of the integers.
  */
int op_div(int a, int b)
{
	return (a / b);
}

/**
  *op_mod - Returns the remainder of the first integer divided by the second.
  *@a: First integer.
  *@b: Second integer.
  *Return: Modulus of the integers.
  */
int op_mod(int a, int b)
{
	return (a % b);
}
