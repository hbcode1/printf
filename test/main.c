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
	char *temp = NULL;
	int len1;
	int len2;
	len1 = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("Character:[%c]\n", 'H');
	len2 = printf("Character:[%c]\n", 'H');
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("String:[%s]\n", "I am a string !");
	len2 = printf("String:[%s]\n", "I am a string !");
	printf("len1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%s\n", temp);
	len2 = printf("%s", temp);
	printf("\nlen1 is %d, len2 is %d\n", len1, len2);
	len1 = _printf("%%");
	len2 = printf("%%");
	printf("\nlen1 is %d, len2 is %d\n", len1, len2);

	return (0);
}