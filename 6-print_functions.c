#include "main.h"

/**
 * print_case_ptr - prints the case for a pointer
 * @arg: list of arguments
 * @option: option for the secifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Return: integer showing number of chars written
 */
int print_case_ptr(va_list *arg, int option, int f, int w, int p, int s)
{
	unsigned long int num;
	int len = 0, i = 0;
	char map[] = "0123456789abcdef", *temp = "";
	void *addr = va_arg(*arg, void *);
	(void)option, (void)p, (void)s;

	if (addr == NULL)
	{
		temp = "(nil)";
		while (*temp)
			len += _putchar(*temp++);
		return (len);
	}
	num = (unsigned long)addr;
	if (w && f) /* just for checks and compilation purposes*/
	{
		while (num)
		{
			temp[i++] = map[num % 16];
			num /= 16;
		}
	}
	while (*temp)
		len += _putchar(*temp++);
	return (len);
}
