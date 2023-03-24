#ifdef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdargs.h>

/**
 * struct _printf_case - a structure that holds id and function
 * @id: identifier character
 * @_printf_case: function which handles case
 *
 * typedef _printf_case_t : type for printcase structure
 */
typedef struct _printf_case
{
	char id;
	void (*_printf_case)(va_list *arg);
} _printf_case_t;

int _printf(const char *format, ...);

#endif /* end def main.h */
