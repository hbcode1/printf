#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 * @specifier: format specifier
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg, int specifier)
{
	char c;
	int len = 0;

	c = va_arg(*arg, int);

	if (specifier == 0)
	{
		len += _putchar(c);
	}
	return (len);
}
