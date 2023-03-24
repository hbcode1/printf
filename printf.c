#include "main.h"

/**
 * _printf - prints out a formatted string
 * @format: string being printed out
 * @...: variable input parameters
 *
 * Description: Takes in a string @format and variable inputs which change
 * The string into whatever formatted that is prescribed
 * Return: integer value describing nuber of chars printed
 */
int _printf(const char *format, ...)
{
	/*
	 * Define all functions here and have ways to call them too
	 */
	int i = 0, j = 0, len = 0;
	va_list args;
	_printf_case_t cases[] = {
		{'c', print_case_char},
		{'d', print_case_int},
		{'i', print_case_dec},
		{'s', print_case_str},
		{0, NULL},
	};

	return (len);
}
