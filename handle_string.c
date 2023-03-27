#include "main.h"

/**
 * print_s - handle string.
 */

int *print_string(char *str, int *len, int t)
{
	char *hex;
	if (str)
	{
		while (*str != '\0')
		{
			if (t == 1 && ((*str > 0 && *str < 32) || *str >= 127))
			{
				*len += _putchar('\\');
				*len += _putchar('x');
				if (*str < 16)
				{
					*len += _putchar('0');
				}
				itoa(*str, hex, 17);
				while (*hex != '\0')
				{
					*len += _putchar(*hex);
					hex++;
				}
				str++;
			}
			*len += _putchar(*str);
			str++;
		}
	}
	return (len);
}
