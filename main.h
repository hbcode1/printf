#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

#define BUFF_SIZE 1024

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
	int (*print_case)(va_list *arg, int specifier);
} _printf_case_t;
/**
 * u_i - typedef for unsigned int
 */
typedef unsigned int u_i;
/*
 * Description: function prototypes for task 0
 */
int _putchar(char c);
int _printf(const char *format, ...);
_printf_case_t *handle_cases();
int print_case_char(va_list *arg, int specifier);
int print_case_str(va_list *arg, int specifier);
=======

/*Task 1*/
char *itoa(u_i n, char *str, int b);
int print_case_int(va_list *arg, int specifier);

/*Task 4*/
void print_buffer(char buffer[], int *index);

/*Task 5*/
int print_case_cstr(va_list *arg, int specifier);

#endif
