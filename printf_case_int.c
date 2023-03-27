#include "main.h"

/**
 * capitalise_chars - capitalises characters in a hex for case 17
 * @str: given string that will be resolved and capitallised
 *
 * Return: pointer to string
 */
void capitalise_chars(char *str)
{
	int i = 0;

	for (i = 0; i < 8; i++)
	{
		if (str[i] > 96 && str[i] < 123)
		{
			str[i] = str[i] - 'a' + 'A';
		}
	}
}
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
		if (num < 0)
		{
			num *= -1;
			len += _putchar('-');
		}
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
		num2 = va_arg(*arg, int);
		temp = itoa(num2, temp, specifier);
		if (specifier == 17)
			capitalise_chars(temp);
	}
	while (*temp)
		len += _putchar(*temp++);
	return (len);
}
