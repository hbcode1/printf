#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg, int specifier, int width)
{
	char c;
	int len = 0;
	c = va_arg(*arg, int);
	if (specifier == 0)
	{
		while (width)
			len += _putchar(' ');
		len += _putchar(c);
	}
	return (1);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 *
 * Return: integer showing number of chars written
 */
int print_case_str(va_list *arg, int specifier, int width)
{
	char *temp;
	int len = 0;

	temp = malloc(sizeof(char) * (100));
	if (temp == NULL)
		return (0);
	temp = va_arg(*arg, char *);
	if (specifier == 0)
	{
		while (width)
			len += _putchar(*temp++), width--;
		if (temp == NULL)
			temp = "(nil)";
		while (*temp)
			len += _putchar(*temp++);
	}
	return (len);
}

/**
 * print_case_int - prints case for format of d
 * @arg: list of arguments
 *
 * Return: integer of number of things writted
 */
int print_case_int(va_list *arg, int specifier, int width)
{
	int num, len = 0;
	char *temp, c;

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
		return (0);
	num = va_arg(*arg, int);
	if (specifier == 0)
	{
		specifier = 10;
		c = ' ';
	}
	temp = itoa(num, temp, specifier);
	while (width)
		len += _putchar(c), width--;
	while (*temp)
		len += _putchar(*temp++);
	return (len);
}
