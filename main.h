#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
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
 * u_i: typedef for unsigned int
 */
typedef unsigned int u_i;
/**
 * u_c: typedef for unsigned char
 */
typedef unsigned char u_c;
int _putchar(char c);
int _printf(const char *format, ...);
_printf_case_t *handle_cases();
int print_case_char(va_list *arg, int specifier);
int print_case_str(va_list *arg, int specifier);
int print_case_int(va_list *arg, int specifier);
int _printf(const char *format, ...);
int _putchar(char c);
int *print_string(char *str, int *len, int t);
int *print_integer(int n, int *len, int base);
int *print_unsigned(u_i n, int *len, int base);
void print_addr(void *addr);
int num_len(unsigned int n);
void rev_str(char *str, int a, int z);
char *itoa(u_i n, char *s, int b);
#endif /* end def main.h */
