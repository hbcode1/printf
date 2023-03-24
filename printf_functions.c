#include "main.h"
/**
 * print_case_char - prints case for format of c
 * @arg: list of arguments
 *
 * Return: Nothing
 */
void print_case_char(va_list *arg)
{
	char c;

	c = va_arg(*arg, int);
	printf("%c", c);
}

/**
 * print_case_str - prints case for format of s
 * @arg: list of arguments
 *
 * Return: Nothing
 */
void print_case_str(va_list *arg)
{
	char *temp;

	temp = va_arg(*arg, char *);
	if (temp == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", temp);
}

/**
 * print_case_int - prints case for format of i
 * @arg: list of arguments
 *
 * Return: Nothing
 */
void print_case_int(va_list *arg)
{
	int num;

	num = va_arg(*arg, int);
	printf("%d", num);
}

/**
 * print_case_dec - prints case for format of d
 * @arg: list of arguments
 *
 * Return: Nothing
 */
void print_case_dec(va_list *arg)
{
	int num;

	num = va_arg(*arg, int);
	printf("%d", num);
}