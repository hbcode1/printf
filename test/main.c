#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
/*	printf("Unknown:[%r]\n");
*/
	_printf("******************EXTRA-TESTS***********************\n\n");
	_printf("# Return the exact length of printed integer plus format\n\n");

	len = _printf("Length:[%d, %i]\n", 456789231, -456789231);
	len2= printf("Length:[%d, %i]\n\n", 456789231, -456789231);

	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n\n", len2);

	_printf("# Return the exact length of printed usigned plus format\n\n");
	len = _printf("Unsigned hexadecimal:[%d, %i]\n", ui, ui);
	len2 = printf("Unsigned hexadecimal:[%d, %i]\n\n", ui, ui);

	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n\n", len2);

	_printf("# Return the exact length of printed string plus format\n\n");

	len = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n\n", "I am a string !");
	
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n\n", len2);

	_printf("Handle custom conversion specifier b (binary)\n\n");
	_printf("98 to binary [%b]\n\n", 98);

	_printf("# Task 5 Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \\x , followed by the ASCII code value in hexadecimal (upper case - always 2 characters)\n\n");

	/* _printf("%S","\ta\bg\n"); */
	_printf("%S\n", "Best\nSchool");
	_printf("\n");
	_printf("%S\n", "Best\tSchool");
	return (0);
}
