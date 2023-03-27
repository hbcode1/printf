#include "main.h"
/**
 * printf_case_addr - prints the address of a value
 * @arg: list of arguments
 * @specifier: int number that specifies case for output
 *
 * Return: integer showing number of outputted char strings
 */
int print_case_addr(va_list *arg, int specifier)
{
	/*
	 * get arg and as address
	 */
	int len = 0;
	unsigned long int num;
	char *temp;

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
		return (0);
	if (specifier == 0)
	{
		num = va_arg(*arg, unsigned long int);
		temp = itoa(num, temp, 16);
	}
	while (temp)
		len += _putchar(*temp++);
	return (len);
}
