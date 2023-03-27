#include "main.h"

/**
 * handle_cases - returns a pointer to some cases
 *
 * Return: integer for cases
 */
_printf_case_t *handle_cases(void)
{
	int i, len = 12;
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
		{'S', print_case_cstr},
		{'p', print_case_ptr},
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

/**
 * handle_cases - returns a pointer to some cases
 *
 * Return: integer for cases
 */
_flag_t *handle_flags(void)
{
	int i, len = 6;
	_flag_t *c;
	_flag_t cases[] = {
		{'-', 1},
		{'+', 2},
		{'0', 4},
		{'#', 8},
		{' ', 16},
		{0, 0},
	};
	c = malloc(sizeof(_flag_t) * len);
	if (c == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		c[i] = cases[i];
	}

	return (c);
}