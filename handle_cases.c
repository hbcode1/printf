#include "main.h"

/**
 * handle_cases - returns a pointer to some cases
 *
 * Return: integer for
 */
_printf_case_t *handle_cases()
{
	int i, len = 3;
	_printf_case_t *c;
	_printf_case_t cases[] = {
		{'c', print_case_char},
		{'s', print_case_str},
		{0, NULL},
	};
	c = malloc(sizeof(_printf_case_t) * len);
	if (c == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		c[i] = cases[i];
	}

	return (c);
}
