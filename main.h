#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

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
	void (*print_case)(va_list *arg);
} _printf_case_t;

int _putchar(char c);
int _printf(const char *format, ...);
void print_case_char(va_list *arg);
void print_case_str(va_list *arg);
void print_case_int(va_list *arg);
void print_case_dec(va_list *arg);

#endif /* end def main.h */
