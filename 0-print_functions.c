#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 * @specifier: format specifier
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg, int specifier)
{
	char c;
	int len = 0;

	c = va_arg(*arg, int);

	if (specifier == 0)
	{
		len += _putchar(c);
	}
	return (len);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 * @specifier: format specifier
 *
 * Return: integer showing number of chars written
 */
int print_case_str(va_list *arg, int specifier)
{
	char *temp;
	int len = 0;

	temp = malloc(sizeof(char) * (100));
	if (temp == NULL)
		return (0);
	temp = va_arg(*arg, char *);
	if (specifier == 0)
	{
		if (temp == NULL)
			temp = "(nil)";
		while (*temp)
			len += _putchar(*temp++);
	}
	return (len);
}