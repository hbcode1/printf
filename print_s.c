#include "main.h"

/**
 * print_s - handle string.
 */

void print_s(char *str)
{
	if (str)
	{
		while (*str != '\0')
		{
			_putchar(*str);
			str++;
		}
	}
}
