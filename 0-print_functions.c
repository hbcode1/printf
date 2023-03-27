#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 * @option: option for the specifier
 *
 * Return: integer showing number of chars written
 */
int print_case_char(va_list *arg, int option)
{
	char c;
	int len = 0;

	c = va_arg(*arg, int);

	if (option == 0)
	{
		len += _putchar(c);
	}
	return (len);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 *
 * Return: integer showing number of chars written
 */
int print_case_str(va_list *arg, int option)
{
	char *temp;
	int len = 0;

	temp = malloc(sizeof(char) * (100));
	if (temp == NULL)
		return (0);
	temp = va_arg(*arg, char *);
	if (option == 0)
	{
		if (temp == NULL)
			temp = "(null)";
		while (*temp)
			len += _putchar(*temp++);
	}
	return (len);
}
