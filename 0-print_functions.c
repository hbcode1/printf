#include "main.h"
int print_string(char *str);
int _strlen(char *str);
int print_padding(char padding, int n);
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 * @option: option for the specifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Description: char can get padded from left or right due to field width
 *				->if flag gives a '-' then right padding, if '+' then left *				padding
 *				->padding could be with 0s or ' 's
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg, int option, int f, int w, int p, int s)
{
	char c, padding = ' ';
	int len = 0, i;
	(void)p, (void)s, (void)option;

	c = va_arg(*arg, int);
	if (c == 0)
		return (-1);

	if (w > 1 && (f & FLAGS_MINUS || f & FLAGS_NONE))
		len += _putchar(c) + print_padding(padding, w - 1);
	else
		len += print_padding(padding, w - 1) + _putchar(c);
	return (len);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Description: strings get padded so s and p modifiers are void
 *				-> if flag gives a '-' then right padding, if '+' then left *				padding
 *				-> padding is done with ' 's
 *				-> string checks if w > length of given first
 *
 * Return: integer showing number of chars written
 */
int print_case_str(va_list *arg, int option, int f, int w, int p, int s)
{
	char *temp, padding = ' ';
	int len = 0, temp_len, i;
	(void)s, (void)p;

	temp = va_arg(*arg, char *);
	if (option == 0)
	{
		if (temp == NULL)
			temp = "(null)";
		temp_len = _strlen(temp);
		if (temp_len < w && (f & FLAGS_MINUS))
			len += print_string(temp) + print_padding(padding, w - temp_len);
		else if (temp_len < w)
			len += print_padding(padding, w - temp_len) + print_string(temp);
		else if (temp_len >= w)
			len += print_string(temp);
	}
	return (len);
}

/**
 * _strlen - gives the length of the string
 * @str: string given
 *
 * Return: length of the string in integer form
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * print_string - prints the string
 * @str: string to be printed
 *
 * Return: number of chars printed
 */
int print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		_putchar(str[i++]);
	return (i);
}

/**
 * print_padding - prints padding up to n times
 * @padding: character used for padding
 * @n: number of pads to apply
 *
 * Return: integer showing number of chars printed
 */
int print_padding(char padding, int n)
{
	int i, len = 0;

	for (i = 0; i < n; i++)
		len += _putchar(padding);

	return (len);
}
