#include "main.h"

/**
 * print_case_cstr - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Return: integer showing number of chars written
 */
int print_case_rev(va_list *arg, int option, int f, int w, int p, int s)
{
	char *temp, *txt, padding = ' ';
	int len = 0, temp_len, i, j = 0;
	(void)s, (void)p;

	temp = va_arg(*arg, char *);
	txt = malloc((_strlen(temp) + 1) * sizeof(char));
	if (txt == NULL)
	{
		return (0);
	}
	for (i = _strlen(temp) - 1; i >=0; i--)
	{
		txt[j] = temp[i];
		j++;
	}
	temp = txt;
	if (option == 0)
	{
		if (temp == NULL)
			temp = "(null)";
		temp_len = _strlen(temp);
		if (temp_len < w && (f & FLAGS_MINUS))
		{
			len += print_string(temp);
			for (i = 0; i < w - temp_len; i++)
				len += _putchar(padding);
		}
		else if (temp_len < w)
		{
			for (i = 0; i < w - temp_len; i++)
				len += _putchar(padding);
			len += print_string(temp);
		}
		else if (temp_len >= w)
			len += print_string(temp);
	}
	return (len);
}
