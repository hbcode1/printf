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
	int i = 0, k = 0, len = 0, printed = 0, flag, width, precision, size;
	va_list args;
	_printf_case_t *cases = handle_cases();
	_flag_t *flags = get_flags();
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
			flag = handle_flags(format, &i, flags);
			width = get_width(format, &i, &args);
			precision = get_precision(format, &i, &args);
			size = get_size(format, &i);
			printed = handle_printing(format, &i, &args, cases, flag, width, precision, size);
			if (printed == -1)
				return (-1);
			len += printed;
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	print_buffer(buffer, &k);
	va_end(args);
	return (len);
}
