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
 * print-integers - helper function for printing integers
 * @str: string representation of number
 * @is_neg: checks for negative number. 0 if not, 1 if true
 * @option: int number that specifies case for output
 * @f: flags
 * @w: field width
 * @s: size
 *
 * Description: -> deals with w(width), f(flags) and s(size)
 *				-> width: just print padding as long as w > strlen
 *					two padding types: '0' and ' ', 0 fill for left pad only
 *				-> flags: '+' and '-' have effect of making print the sign
 *					they also justify content, + is right, - in left
 *					' ' before any other flag turns the '+' to a ' ' sign
 *				-> size: two sizes: l(long) and h(short)
 *
 * Return: intger showing number of chars printed
 */
int print_integer(char *str, int is_neg, int option, int f, int w, int s)
{
	int len = 0, i, j, string_len = _strlen(str);
	char neg_sign = '-', padding = ' ';

	if (f & FLAGS_ZERO)
		padding = '0';
	if (string_len < w && f & FLAGS_MINUS)
	{
		
	}
	while (str[i])
		len += _putchar(str[i++]);

	return (len);
}

/**
 * print_case_int - prints case for format of d
 * @arg: list of arguments
 * @option: int number that specifies case for output
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Description: cases for specifier are here...
 *				0 for normal integers
 *				1 for unsigned integers
 *				2 for binary
 *				8 for octal
 *				16 for hexadecimal
 *				17 for capitalised hex
 *				-> int needs w, s, f arguments
 * Return: integer of number of things writted
 */
int print_case_int(va_list *arg, int option, int f, int w, int p, int s)
{
	int num = 0, len = 0, is_neg = 0;
	unsigned int num2 = 0;
	char *temp;
	(void)p;

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
		return (0);

	if (option == DEFAULT_OPTION)
		option = DECIMAL_OPTION, num = va_arg(*arg, int);
	else if (option == BINARY_OPTION)
		num = va_arg(*arg, int);
	else if (option == UNSIGNED_OPTION)
		num2 = va_arg(*arg, unsigned int), option = DECIMAL_OPTION;
	else if (option == OCTAL_OPTION || option == HEX_OPTION || option == CAPPED_HEX_OPTION)
		num = va_arg(*arg, int);

	if (num < 0)
		num *= -1, is_neg = 1;
	if (option != UNSIGNED_OPTION)
		temp = itoa(num, temp, option);
	else if (option == UNSIGNED_OPTION)
		temp = itoa(num2, temp, option);

	if (option == CAPPED_HEX_OPTION)
		capitalise_chars(temp);
	len += print_integer(temp, is_neg, option, f, w, s);
	return (len);
}
