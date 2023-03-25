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

	c = va_arg(*arg, int);
	if (specifier == 0)
		_putchar(c);
	return (1);
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

	temp = malloc(sizeof(char) * 100);
	temp = va_arg(*arg, char *);
	if (specifier == 0)
	{
		if (temp == NULL)
			temp = "(nil)";
		while (*temp)
		{
			_putchar(*temp++);
			len++;
		}
	}
	return (len);
}

/**
 * print_case_int - prints case for format of i
 * @arg: list of arguments
 * @specifier: checks if integer is meant to be converted
 *
 * Descrition: if @specifier is 0, then do decimal
 *		if 1, then do octal, if 2 then do hex
 * Return: integer showing number of chars written
 */
int print_case_int(va_list *arg, int specifier)
{
	int num, len = 0;
	char *temp;

	temp = malloc(sizeof(char) * 100);
	num = va_arg(*arg, int);
	if (specifier == 0)
		temp = itoa(num, temp, 10);
	else if (specifier == 1)
		temp = itoa(num, temp, 8);
	else if (specifier == 2)
		temp = itoa(num, temp, 16);
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
int print_case_dec(va_list *arg, int specifier)
{
	int num, len = 0;
	char *temp;

	temp = malloc(sizeof(char) * 100);
	num = va_arg(*arg, int);
	if (specifier == 0)
		temp = itoa(num, temp, 10);
	while (*temp)
	{
		_putchar(*temp++);
		len++;
	}
	return (len);
}