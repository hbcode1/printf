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
				print_string(str, &len, 0);
				len++;
				break;
			/* print costum string */
			case 'S':
				str = va_arg(argp, char *);
				print_string(str, &len, 1);
				len++;
				break;
			/* print integers */
			case 'i':
				print_integer(va_arg(argp, int), &len, 10);
				break;
			case 'd':
				print_integer(va_arg(argp, int),&len, 10);
				len++;
				break;
			case 'b':
				print_integer(va_arg(argp, int),&len, 2);
				len++;
				break;
			/* print unsigneds*/
			case 'u':
				print_unsigned(va_arg(argp, u_i),&len, 10);
				len++;
				break;
			case 'o':
				print_unsigned(va_arg(argp, u_i),&len, 8);
				len++;
				break;
			case 'x':
				print_unsigned(va_arg(argp, u_i),&len, 16);
				len++;
				break;
			case 'X':
				print_unsigned(va_arg(argp, u_i),&len, 17);
				len++;
				break;
			/* print address*/
			case 'p':
				_putchar(*fmt);
				len++;
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
