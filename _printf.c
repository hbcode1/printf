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
	int i = 0, j = 0, k = 0, len = 0, option = 0;
	va_list args;
	_printf_case_t *cases = handle_cases();
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[k++] = format[i];
			if (k == BUFF_SIZE)
				print_buffer(buffer, &k);
			len++;
		}
		else if (format[i] == '%')
		{
			print_buffer(buffer, &k);
			i++;
			if (format[i] == '%')
			{
				len += _putchar('%'), i++;
				continue;
			}
			while (cases[j].id != format[i] && cases[j].id)
				j++;
			if (j < 11)
			{
				option = ((j == 4)	? 2
						: (j == 5) ? 1
						: (j == 6) ? 8
						: (j == 7) ? 16
						: (j == 8) ? 17
						: (j == 9) ? 3
						:0);
				len += cases[j].print_case(&args, option);
			}
			if (j >= 11)
			{
				len += _putchar('%');
				len += _putchar(format[i]);
			}
		}
		else
			len += _putchar(format[i]);
		j = 0, i++, option = 0;
	}
	print_buffer(buffer, &k);
	va_end(args);
	return (len);
}
