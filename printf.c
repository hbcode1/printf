#include "main.h"

/**
 * _printf - prints out a formatted string
 * @format: string being printed out
 * @...: variable input parameters
 *
 * Description: Takes in a string @format and variable inputs which change
 * The string into whatever formatted that is prescribed
 * Return: integer value describing number of chars printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args;
	_printf_case_t cases[] = {
		{'c', print_case_char},
		{'d', print_case_int},
		{'i', print_case_dec},
		{'s', print_case_str},
		{0, NULL},
	};

	va_start(args, format);
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			while (cases[j].id != format[i] && cases[j].id)
				j++;
			if (j < 4)
			{
				if (format[i] == '0' && format[i + 1])
					len += cases[j].print_case(&args);
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}
		j = 0, i++;
	}

	va_end(args);
	return (len);
}
