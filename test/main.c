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

	char *temp = "Hello";
	int len1;
	int len2;
    void *addr;
	_printf("String[%r]\n", "STRING");
	_printf("String[%r][%r]\n", "String", "gnirtS");

	
	addr = (void *)0x7ffe637541f0;

    _printf("pAddress:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
	_printf("%S\n", "Best\nSchool");
	_printf("%S\n", "Best\tSchool");
	_printf("%S\n", "Best\t\nSchool");
	_printf("%S\n", "Best\t\nSchoo\nl");
	len1 = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%10s\n", temp);
	len2 = printf("%10s\n", temp);
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%10c\n", 'A');
	len2 = printf("%10c\n", 'A');
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%-10c\n", 'A');
	len2 = printf("%-10c\n", 'A');
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%-10s\n", temp);
	len2 = printf("%-10s\n", temp);
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%*s\n", 10, temp);
	len2 = printf("%*s\n", 10, temp);
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("before%%\n");
	len2 = _printf("before%%\n");
	printf("len1 is %d, len2 is %d\n", len1, len2);
	printf("before%");
	_printf("");
	printf("");
	printf("\nlen1 is %d, len2 is %d\n", len1, len2);

	printf("\nlen1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%p pointer", (void *)&len1);
	len2 = printf("%p pointer", (void *)&len1);
	printf("\nlen1 is %d, len2 is %d\n", len1, len2);
	return (0);
}