#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * uint_print - Function that print a unsigned int
 *
 * @args: Variadic list of arguments
 * Return: Count of arguments printed
 */
int uint_print(va_list args)
{

	unsigned int num, div, i = 0;

	num = va_arg(args, int);

	if (num == 0)
	{
		_putchar('0');
		i = 1;
	}
	if (num > 0)
	{
		for (div = 1; (num / div) > 9; div *= 10)
			;
		while (div != 0)
		{
			_putchar((num / div) + '0');
			num %= div;
			div /= 10;
			i++;
		}
	}
	return (i);

}
/**
 * oct_print - Function that print an octal
 *
 * @args: Variadic list of arguments
 * Return: Count of arguments printed
 */

int oct_print(va_list args)
{

	unsigned int num, i = 0, j = 0;
	int nums[100];

	num = va_arg(args, int);

	if (num < 9)
	{
		_putchar(num + '0');
		i = 1;
	}
	else if (num >= 9)
	{
		while (num > 0)
		{
			nums[j] = num % 8;
			num /= 8;
			j++;
		}
	}
	while (j--)
	{
		_putchar(nums[j] + '0');
		i++;
	}
	return (i);
}
/**
 * print - Dummy Function
 * @args: Variadic list of arguments
 * Return: 0 for control
 */

int print(va_list args)
{
	(void)args;
	return (0);
}

