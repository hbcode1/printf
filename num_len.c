#include "main.h"
/**
 * find_length - find length of a number
 * @n: number to check
 * Return: length
 */
int num_len(unsigned int n)
{
	u_i l, i;

	l = 1;
	for (i = 0; i <= 10; i++)
	{
		if (n / 10)
		{
			l = l + 1;
			n = n / 10;
		}
		else
			break;
	}
	return (l);
}
