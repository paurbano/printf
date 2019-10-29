#include "holberton.h"
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
	op_print op[] = {{"c", char_print}, {"s", str_print}, {"%", percent_print},
		{"x", print}, {"f", print}, {"e", char_print}, {"g", print},
		{"i", int_print}, {"d", int_print}, {"u", uint_print}, {"o", print}};

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		while (format[i] != '%' && format[i] != '\0')
		{
			_putchar(format[i]);
			counter++;
			i++;
		}
		if (format[i] != '\0')
			i++;
		else
			break;
		for (j = 0; j < 11; j++)
		{
			if (format[i] == *(op[j]).format)
			{
				counter += op[j].function(args);
				break;
			}
		}
		while (j == 11 && format[i - 1] != '\0')
		{
			_putchar(format[i - 1]);
			i++;
		}
	}
	va_end(args);
	return (counter);
}
