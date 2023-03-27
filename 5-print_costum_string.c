#include "main.h"
/**
 * print_case_cstr - prints case for format of s
 * @arg: list of arguments
 * @option: option for the secifier
 *
 * Return: integer showing number of chars written
 */
int print_case_cstr(va_list *arg, int option)
{
	char *temp, *hex;
	int len = 0;

	hex = malloc(sizeof(char) * 3);
	if (hex == NULL)
		return (0);

	temp = va_arg(*arg, char *);
	if (option == 3)
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
					temp++;
				}
			}
			len += _putchar(*temp++);
		}
	}
	return (len);
}
