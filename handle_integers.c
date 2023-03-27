#include "main.h"

/**
 * print_s - handle string.
 */

int *print_integer(int n, int *len, int b)
{
	char *str;
	u_i u_n;

	if (n < 0)
	{
		*len += _putchar('-');
		n = -(n);
	}
	str = malloc(sizeof(int) * 10 + 1);
	u_n = (u_i) n;
	itoa(u_n, str, b);
	while (*str != '\0')
	{
		*len += _putchar(*str);
		str++;
	}
	return (len);
}