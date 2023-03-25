#include "main.h"

/**
 * handle_cases - returns a pointer to some cases
 * @c: string at that point
 *
 * Return: integer for
 */
_printf_case_t *handle_cases()
{
	int i, len = 6;
	_printf_case_t *c;
	_printf_case_t cases[] = {
		{'c', print_case_char},
		{'i', print_case_int},
		{'d', print_case_int},
		{'s', print_case_str},
		{'b', print_case_int},
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
