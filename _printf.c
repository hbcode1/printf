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
	int i = 0, j = 0, len = 0, option = 0;
	va_list args;
	_printf_case_t *cases = handle_cases();

	va_start(args, format);

	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				len += _putchar('%'), i++;
				continue;
			}
			while (cases[j].id != format[i] && cases[j].id)
				j++;
			if (j < 2)
			{
				len += cases[j].print_case(&args, option);
			}
			if (j == 2)
			{
				len += _putchar(format[i]);
			}
		}
		else
			len += _putchar(format[i]);
		j = 0, i++, option = 0;
	}

	va_end(args);
	return (len);
}
