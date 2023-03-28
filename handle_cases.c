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
		{'r', print_case_rev},
		{'R', print_case_rot},
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
_flag_t *get_flags(void)
{
	int i, len = 6;
	_flag_t *c;
	_flag_t cases[] = {
		{'-', FLAGS_MINUS},
		{'+', FLAGS_PLUS},
		{'0', FLAGS_ZERO},
		{'#', FLAGS_HASH},
		{' ', FLAGS_SPACE},
		{0, FLAGS_NONE},
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

/**
 * is_num - checks if a char is a number
 * @c: character being checked
 *
 * Return: 1 if true, 0 if false
 */
int is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}