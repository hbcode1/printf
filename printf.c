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
	int i = 0, j = 0, len = 0, specifier = 0;
	va_list args;
	_printf_case_t *cases = handle_cases();

	va_start(args, format);

	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			while (cases[j].id != format[i] && cases[j].id)
				j++;
			if (j == 10)
			{
				len += _putchar('%'), i++;
				continue;
			}
			if (j < 12 && j != 10)
			{
				specifier = ((j == 4)	? 2
							 : (j == 5) ? 1
							 : (j == 6) ? 8
							 : (j == 7) ? 16
							 : (j == 8) ? 17
										: 0);
				len += cases[j].print_case(&args, specifier);
			}
		}
		else
			len += _putchar(format[i]);
		j = 0, i++, specifier = 0;
	}
	va_end(args);
	return (len);
}
