#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
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

/**
 * print_case_int - prints case for format of d
 * @arg: list of arguments
 *
 * Return: integer of number of things writted
 */
int print_case_int(va_list *arg, int specifier)
{
	int num = 0, len = 0;
	unsigned int num2 = 0;
	char *temp;

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
		return (0);
	if (specifier == 0)
	{
		specifier = 10, num = va_arg(*arg, int);
		temp = itoa(num, temp, specifier);
	}
	if (specifier == 2)
	{
		num = va_arg(*arg, int);
		temp = itoa(num, temp, specifier);
	}
	if (specifier == 1)
	{
		num2 = va_arg(*arg, unsigned int), specifier = 10;
		temp = itoa(num2, temp, specifier);
	}
	if (specifier == 8 || specifier == 16 || specifier == 17)
	{
		if (specifier == 17)
			specifier--;
		num2 = va_arg(*arg, int);
		temp = itoa(num2, temp, specifier);
	}
	while (*temp)
		len += _putchar(*temp++);
	return (len);
}
