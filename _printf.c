#include "holberton.h"
#include <stdlib.h>

/**
 * _printf - Function that prints according to a specifier
 * @format: The format to print
 * Return: The count of parameters printed by the function
 */

int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0, i, j;
	op_print op[] = {
		{"c", char_print}, {"s", str_print}, {"%", percent_print},
		{"i", int_print}, {"d", int_print}, {"u", uint_print}};

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			_putchar(format[i]);
			counter++;
			i++;
		}
		if (format[i] != '\0')
		{
			i++;
		}
		else
			break;
		for (j = 0; j < 6; j++)
		{
			if (format[i] == *(op[j]).format)
			{
				counter += op[j].function(args);
				break;
			}
			else
			{
				_putchar(format[i]);
				break;
			}
		}
	}
	va_end(args);
	return (counter);
}
