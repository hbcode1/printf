#include "main.h"

/**
 * get_width - gets the width that would be used for printing
 * @format: format string that has width
 * @index: index inside format string
 * @arg: argument list in case of *
 *
 * Return: width as an integer
 */
int get_width(const char *format, int *index, va_list *arg)
{
	int i, width = 0, j = *index, k = 0;

	for (i = *index; format[i] != '\0' && format[i] != '%'; i++)
	{
		if (is_num(format[i]))
		{
			width *= 10;
			width += format[i] - '0';
			k++;
		}
		else if (format[i] == '*')
		{
			k++;
			width = va_arg(*arg, int);
			break;
		}
		else
			break;
	}
	if (!k)
		*index = j;
	else
		*index = j + k;

	return (width);
}

/**
 * get_precision - gets the precision that would be used for printing
 * @format: format string that has width
 * @index: index inside format string
 * @arg: argument list in case of *
 *
 * Return: precision as an integer
 */
int get_precision(const char *format, int *index, va_list *arg)
{
	int i = *index, precision = -1, j = *index, k = 0;

	if (format[i] == '.')
	{
		precision = 0, i++;
		for (i = *index; format[i] != '\0' && format[i] != '%'; i++)
		{
			if (is_num(format[i]))
			{
				precision *= 10;
				precision += format[i] - '0';
				k++;
			}
			else if (format[i] == '*')
			{
				k++;
				precision = va_arg(*arg, int);
				break;
			}
			else
				break;
		}
	}
	if (!k)
		*index = j;
	else
		*index = j + k;

	return (precision);
}

/**
 * get_size - deals with the size modifier eg l or h for integers and floats
 * @format: format string where modifiers are held
 * @index: current index in _printf
 *
 * Return: size as an integer
 */
int get_size(const char *format, int *index)
{
	int i = *index, size = 0, j = *index;

	if (format[i] == 'l')
		size = LONG_SIZE;
	if (format[i] == 'h')
		size = SHORT_SIZE;
	if (size == 0)
		*index = j;
	else
		*index = j + 1;

	return (size);
}
