#include "main.h"
#include <stdio.h>

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
	int len = 0, i = 0;
	char *temp = "", *hex = "";
	void *ptr;
	l_u_i addr;
	(void)option, (void)p, (void)s;
	
	ptr = va_arg(*arg, void *);
	addr = (l_u_i)ptr;

	hex = malloc(sizeof(char) * 12);
	if (hex == NULL)
	{
		return (0);
	}
	if (ptr == NULL)
	{
		temp = "(nil)";
		while (*temp)
			len += _putchar(*temp++);
		return (len);
	}
	if (!w && !f && !i) /* just for checks and compilation purposes*/
	{
		itoa(addr, hex, 16);
		len += _putchar('0');
		len += _putchar('x');
		while (*hex != '\0')
		{
			len += _putchar(*hex);
			hex++;
		}					
		
	}
	return (len);
}
