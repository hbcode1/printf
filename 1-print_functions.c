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
 * print_filling - prints the filling using the precision value
 * @filling: char used for filling
 * @n: number of chars used to fill
 *
 * Return: number of times chars are printed
 */
int print_filling(char filling, int n)
{
	int i, len = 0;

	for (i = 0; i < n; i++)
		len += _putchar(filling);

	return (len);
}

/**
 * print_sign - print the sign of he integer based on it's flags
 * @f: flag
 * @is_neg: integer showing neative state. 0 is false, 1 is true
 *
 * Return: integer showing number of chars printed
 */
int print_sign(int f, int is_neg)
{
	int len = 0;
	char neg_sign = '-', pos_sign = '+', spc_sign = ' ';

	if (is_neg)
		len += _putchar(neg_sign);
	if (f & FLAGS_PLUS && !is_neg)
		len += _putchar(pos_sign);
	else if (f & FLAGS_SPACE && (f & FLAGS_PLUS || f & FLAGS_MINUS))
		len += _putchar(spc_sign);

	return (len);
}

/**
 * print_integer - helper function for printing integers
 * @str: string representation of number
 * @is_neg: checks for negative number. 0 if not, 1 if true
 * @f: flags
 * @w: field width
 * @p: precision
 *
 * Description: -> deals with w(width), f(flags) and s(size)
 *				-> width: just print padding as long as w > strlen
 *					two padding types: '0' and ' ', 0 fill for left pad only
 *				-> flags: '+' and '-' have effect of making print the sign
 *					they also justify content, + is right, - in left
 *					' ' before any other flag turns the '+' to a ' ' sign
 *				-> size: two sizes: l(long) and h(short)
 *				-> precision: dictates how many chars is printed out
 *					if p < 0, then ignore. if p is 0 then print str,
 *					if p > 0 then use it to count chars in out
 *
 * Return: intger showing number of chars printed
 */
int print_integer(char *str, int is_neg, int f, int w, int p)
{
	int len = 0, i = 0, string_len = _strlen(str);
	char padding = ' ', filling = '0';

	if (f & FLAGS_ZERO)
		padding = '0';
	if (is_neg || (f & FLAGS_PLUS && !is_neg) || (f & FLAGS_SPACE))
		i++;
	if (p <= 0)
	{
		if (string_len < w && (f & FLAGS_MINUS || f & FLAGS_SPACE))
			len += print_sign(f, is_neg) + print_string(str) + print_padding(' ', w - string_len - i);
		else if (string_len < w && !(f & FLAGS_NONE))
		{
			len += print_padding(padding, w - string_len - i);
			len += print_sign(f, is_neg) + print_string(str);
		}
		else if ((string_len < w && (f & FLAGS_PLUS || f & FLAGS_ZERO)) || (f & FLAGS_SPACE))
		{
			len += print_padding(padding, w - string_len - i);
			len += print_sign(f, is_neg) + print_string(str);
		}

		else if (string_len >= w)
			len += print_sign(f, is_neg) + print_string(str);
	}
	else if (p > 0 || p > string_len)
	{
		if (string_len < w && (f & FLAGS_MINUS || f & FLAGS_SPACE))
			len += print_filling(filling, p - string_len) + print_sign(f, is_neg) + print_string(str) + print_padding(' ', w - p - string_len - i);
		else if (string_len < w && !(f & FLAGS_NONE))
		{
			len += print_padding(padding, w - p - string_len - i);
			len += print_filling(filling, p - string_len) + print_sign(f, is_neg) + print_string(str);
		}
		else if ((string_len < w && (f & FLAGS_PLUS || f & FLAGS_ZERO)) || (f & FLAGS_SPACE))
		{
			len += print_padding(padding, w - p - string_len - i);
			len += print_filling(filling, p - string_len) + print_sign(f, is_neg) + print_string(str);
		}

		else if (string_len >= w)
			len += print_filling(filling, p - string_len) + print_sign(f, is_neg) + print_string(str);
	}
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
	long int num = 0, len = 0, is_neg = 0;
	u_l_i num2 = 0;
	char *temp;

	temp = malloc(sizeof(char) * 100);
	if (temp == NULL)
		return (0);
	if (option == DEFAULT_OPTION)
		option = DECIMAL_OPTION, num = va_arg(*arg, int);
	else if (option == BINARY_OPTION)
		num = va_arg(*arg, long int);
	else if (option == UNSIGNED_OPTION)
		num2 = va_arg(*arg, u_i), option = DECIMAL_OPTION;
	else if (option == OCTAL_OPTION || option == HEX_OPTION ||
			 option == CAPPED_HEX_OPTION)
		num = va_arg(*arg, int);
	if (num < 0)
		{
			if (option == DEFAULT_OPTION)
				num *= -1, is_neg = 1;
		}
	if (option != DECIMAL_OPTION || option != DEFAULT_OPTION)
	{
		if (s)
		{
			if (s == LONG_SIZE)
				temp = itoa((u_l_i)num, temp, option);
			if (s == SHORT_SIZE)
				temp = itoa((u_s_i)num, temp, option);
		}
		else
			temp = itoa(num, temp, option);
	}
	else if (option == DECIMAL_OPTION || option == DEFAULT_OPTION)
	{
		if (s)
		{
			if (s == LONG_SIZE)
				temp = itoa((u_l_i)num2, temp, option);
			if (s == SHORT_SIZE)
				temp = itoa((u_s_i)num2, temp, option);
		}
		else
			temp = itoa(num2, temp, option);
	}
	if (option == CAPPED_HEX_OPTION)
		capitalise_chars(temp);
	len += print_integer(temp, is_neg, f, w, p);
	free(temp);
	return (len);
}
/**
 * print_padding - prints padding up to n times
 * @padding: character used for padding
 * @n: number of pads to apply
 *
 * Return: integer showing number of chars printed
 */
