#include "main.h"
void print_i_d(int n)
{
	u_i max_l, max, m, i;

	m = n;
	if (n < 0)
	{
		m = -n;
		_putchar(45);
	}

	max_l = num_len(m), max = 1;
	for (i = 1; i < max_l; i++)
	{
		max *= 10;
	}
	for (; max > 1; max /= 10)
	{
		_putchar(m / max + '0');
		m = m % max;
	}
	_putchar(m / max + '0');
}
