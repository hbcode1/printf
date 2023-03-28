#include <stdio.h>

/**
 * main - test printf() casually
 *
 * Return: 0 Always
 */
int main(void)
{
	printf("%-5c\n", 'H');
	printf("%10s\n", "Hello");
	printf("%5c\n", 'E');

	return (0);
}