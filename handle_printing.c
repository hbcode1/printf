#include "main.h"

/**
 * handle_printing - helper function to decrease stress of _printf
 * @format: the format string
 * @index: index at that point
 * @arg: argument list to be used
 * @buffer: buffer of max 1024 chars
 * @cases: list of cases to loop through
 * @f: flags
 * @w: field width
 * @p: precision for floats
 * @s: size for integers (l or h modifier)
 *
 * Return: integer showing number of chars printed
 */
int handle_printing(const char *format, int *index, va_list *arg, _printf_case_t *cases, int f, int w, int p, int s)
{
	/*handle printing from here instead of _printf for special cases*/
	int len = 0, i = 0, j = 0, option = 0;

	while (cases[j].id != format[*index] && cases[j].id)
		j++;
	if (j < 12)
	{
		option = ((j == 4)	 ? BINARY_OPTION
				  : (j == 5) ? UNSIGNED_OPTION
				  : (j == 6) ? OCTAL_OPTION
				  : (j == 7) ? HEX_OPTION
				  : (j == 8) ? CAPPED_HEX_OPTION
				  : (j == 9) ? C_STRING_OPTION
							 : DEFAULT_OPTION);
		len += cases[j].print_case(arg, option, f, w, p, s);
	}
	if (j >= 12)
	{
		if (format[*index] == '\0')
			return (-1);
		if (format[*index - 1] == ' ')
			len += _putchar(' ');
		else if (w)
		{
			*index = *index - 1;
			while (format[*index] != ' ' && format[*index] != '%')
				*index = *index - 1;
			if (format[*index] == ' ')
				*index = *index - 1;
			return (1);
		}
		len += _putchar(format[i]);
	}

	return (len);
}
