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
	int i = 0, j = 0, len = 0, specifier = 0, width = 0;
	va_list args;
	_printf_case_t *cases = handle_cases();
	va_start(args, format);
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '0' && format[i + 1] == 'x')
				specifier = 16, i += 2;
			else if (format[i] == '0' && format[i + 1] != 'x')
				specifier = 8, i++;
			else if (format[i] >= '0' && format[i] <= '9')
				width = format[i] - 48, i++;
			while (cases[j].id != format[i] && cases[j].id)
				j++;
			if (j < 5)
			{
				if (j == 4)
					specifier = 2;
				len += cases[j].print_case(&args, specifier, width);
			}
			else if (j == 5 && format[i - 1] == '%' && format[i] != '%')
				len += (_putchar(format[i - 1])) + _putchar(format[i]);
			else if (j == 5)
				len += _putchar(format[i]);
		}
		else
			len += _putchar(format[i]);
		j = 0, i++, specifier = 0;
	}
	va_end(args);
	return (len);
}
