#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>

typedef struct op_print
{
char *format;
int (*function)();
}op_print;

void _putchar(char);
int _printf(const char *, ...);
int int_print(va_list);
int str_print(va_list);
int char_print(va_list);
int percent_print(void);
int uint_print(va_list);

#endif
