#include "main.h"

/**
 * handle_cases - returns a pointer to some cases
 * @c: string at that point
 *
 * Return: integer for
 */
_printf_case_t *handle_cases()
{
	int i, len = 10;
	_printf_case_t *c;
	_printf_case_t cases[] = {
		{'c', print_case_char},
		{'s', print_case_str},
		{'i', print_case_int},
		{'d', print_case_int},
		{'b', print_case_int},
		{'u', print_case_int},
		{'o', print_case_int},
		{'x', print_case_int},
		{'X', print_case_int},
		{'S', print_case_str},
		{'p', print_case_int},
		{'+', print_case_str},
		{' ', print_case_str},
		{'#', print_case_str},
		{'R', print_case_str},
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
