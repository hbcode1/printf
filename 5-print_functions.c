#include "main.h"
/**
 * print_case_cstr - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 * @f: flags
 * @w: field width
 * @p: precision
 * @s: size
 *
 * Return: integer showing number of chars written
 */
int print_case_cstr(va_list *arg, int option, int f, int w, int p, int s)
{
	char *temp, *hex;
	int len = 0;
	(void)p, (void)s;

	hex = malloc(sizeof(char) * 10);
	if (hex == NULL)
		return (0);

	temp = va_arg(*arg, char *);
	if (option == 3 && !f && !w) /*for checking purposes, must be changed in future*/
	{
		if (temp == NULL)
			temp = "(null)";
		while (*temp)
		{
			if ((*temp > 0 && *temp < 32) || *temp >= 127)
			{
				len += _putchar('\\');
				len += _putchar('x');
				if (*temp < 16)
				{
					len += _putchar('0');
				}
				itoa(*temp, hex, 17);
				{
					while (*hex != '\0')
					{
						len += _putchar(*hex);
						hex++;
					}
				}
				temp++;
			}
			else
			{
				len += _putchar(*temp++);
			}
		}
	}
	return (len);
}
