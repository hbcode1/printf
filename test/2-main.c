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
	long int l = UINT_MAX + 1024;
	_printf("%b\n", 1024);
	printf("%b\n", 1024);
	
	_printf("%b\n", -1024);
	printf("%b\n", -1024);
	_printf("%b\n", 0);
	printf("%b\n", 0);
	_printf("%b\n", UINT_MAX);
	printf("%b\n", UINT_MAX);
	_printf("%b\n", l);
	printf("%b\n", l);
	_printf("There is %b bytes in %b KB\n", 1024, 1);
	printf("There is %b bytes in %b KB\n", 1024, 1);
	_printf("%b - %b = %b\n", 2048, 1024, 1024);
	printf("%b - %b = %b\n", 2048, 1024, 1024);
	_printf("%b + %b\n", INT_MAX, INT_MAX);
	printf("%b + %b\n", INT_MAX, INT_MAX);
	return (0);
}