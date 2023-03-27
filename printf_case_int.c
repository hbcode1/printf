#include "main.h"

/**
 * print_case_int - prints case for format of d
 * @arg: list of arguments
 * @specifier: int number that specifies case for output
 *
 * Description: cases for specifier are here...
 *				0 for normal integers
 *				1 for unsigned integers
 *				2 for binary
 *				8 for octal
 *				16 for hexadecimal
 *				17 for capitalised hex
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
