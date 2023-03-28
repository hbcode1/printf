#include "main.h"
/**
 * rot13 - encodes a string using caesar cipher ROT13 encryption
 * @str: string to encode.
 * Return: encoded string.
 */

char *rot13(char *str)
{
	int i = 0, j = 0;
	char letters[] = "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm";

	while (str[j] != '\0')
	{
		while (str[j] != letters[i] && letters[i] != '\0')
		{
			i++;
		}
		if (str[j] == letters[i])
		{
			str[j] = rot13[i];
		}
		i = 0;
		j++;
	}
	return (str);
}
/**
 * print_case_rot - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Return: integer showing number of chars written
 */
int print_case_rot(va_list *arg, int option, int f, int w, int p, int s)
{
	char *temp, padding = ' ';
	int len = 0, temp_len, i;
	(void)s, (void)p;
	temp = va_arg(*arg, char *);
	temp = rot13(temp);
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
