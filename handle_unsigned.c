#include "main.h"

/**
 * print_s - handle string.
 */

int *print_unsigned(u_i n, int *len, int b)
{
	char *str;
	str = malloc(sizeof(u_i) * 10 + 1);
	itoa(n, str, b);
	while (*str != '\0')
	{
		*len += _putchar(*str);
		str++;
	}
	return (len);
}