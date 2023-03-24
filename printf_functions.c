#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg)
{
	char c;

	c = va_arg(*arg, int);
	_putchar(c);
	return (1);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 *
 * Return: integer showing number of chars written
 */
int print_case_str(va_list *arg)
{
	char *temp;
	int len = 0;

	temp = va_arg(*arg, char *);
	if (temp == NULL)
	{
		printf("(nil)");
		return;
	}
	while (*temp)
	{
		_putchar(*temp++);
		len++;
	}
	return (len);
}

/**
 * print_case_int - prints case for format of i
 * @arg: list of arguments
 * @specifier: checks if integer is meant to be converted
 *
 * Return: integer showing number of chars written
 */
int print_case_int(va_list *arg, int specifier)
{
	int num, len = 0;
	char *temp;

	num = va_arg(*arg, int);
	temp = itoa(num, temp, 10);
	while (*temp)
	{
		_putchar(*temp++);
		len++;
	}
	return (len);
}

/**
 * print_case_dec - prints case for format of d
 * @arg: list of arguments
 *
 * Return: integer of number of things writted
 */
int print_case_dec(va_list *arg)
{
	int num, len = 0;
	char *temp;

	num = va_arg(*arg, int);
	temp = itoa(num, temp, 10);
	while (*temp)
	{
		_putchar(*temp++);
		len++;
	}
	return (len);
}