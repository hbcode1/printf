#include "main.h"

/**
 * _printf - function that produces output according to a format.
 *
 * @format: character string.
 *
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list argp;
	char *fmt = strdup(format), *str;
	int len = 0;

	va_start (argp, format);
	while (fmt && *fmt != '\0')
	{
		/* print format as string until reach % */
		while(*fmt && *fmt != '%')
		{
			_putchar(*fmt);
			fmt++;
			len++;
		}
		/* handle format specifiers */
		if (*fmt == '%')
		{
			fmt++;
			switch(*fmt)
			{
			/* print character */
			case 'c':
				_putchar(va_arg(argp, int));
				len++;
				break;
			/* print string */
			case 's':
				str = va_arg(argp, char *);
				print_s(str);
				break;
			/* print integers */
			case 'i':
				print_i_d(va_arg(argp, int));
				break;
			case 'd':
				print_i_d(va_arg(argp, int));
				break;
			/* print precent */
			case '%':
				_putchar('%');
				len++;
				break;
			/* handle unknown specifiers */
			default:
				_putchar('%');
				_putchar(*fmt);
				len++;
				break;
			}
			fmt++;
		}
	}
	va_end(argp);
	return (len);
}
