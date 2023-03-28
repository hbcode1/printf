#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>

#define BUFF_SIZE 1024

/**
 * Description: Flag symbolic constants, to be used when dealing with flags
 */
#define FLAGS_NONE 0
#define FLAGS_MINUS 1
#define FLAGS_PLUS 2
#define FLAGS_ZERO 4
#define FLAGS_HASH 8
#define FLAGS_SPACE 16

#define LONG_SIZE 1
#define SHORT_SIZE 2

#define DEFAULT_OPTION 0
#define UNSIGNED_OPTION 1
#define BINARY_OPTION 2
#define C_STRING_OPTION 3
#define OCTAL_OPTION 8
#define HEX_OPTION 16
#define CAPPED_HEX_OPTION 17

/**
 * struct _printf_case - a structure that holds id and function
 * @id: identifier character
 * @print_case: function which handles case
 *
 * typedef _printf_case_t : type for printcase structure
 */
typedef struct _printf_case
{
	char id;
	int (*print_case)(va_list *arg, int option, int f, int w, int p, int s);
} _printf_case_t;

/**
 * struct _flag - a structure that holds id and a value for flags
 * @id: identifier character
 * @value: value of the flag to be used in handling
 *
 * typedef _flag_t : type for flag structure
 */
typedef struct _flag
{
	char id;
	int value;
} _flag_t;

/**
 * u_i - typedef for unsigned int
 */
typedef unsigned int u_i;

/*Task 0*/
int _putchar(char c);
int _printf(const char *format, ...);
_printf_case_t *handle_cases();
int print_case_char(va_list *arg, int option, int f, int w, int p, int s);
int print_case_str(va_list *arg, int option, int f, int w, int p, int s);

/*Task 1*/
char *itoa(u_i n, char *str, int b);
int print_case_int(va_list *arg, int option, int f, int w, int p, int s);

/*Task 4*/
void print_buffer(char buffer[], int *index);

/*Task 5*/
int print_case_cstr(va_list *arg, int option, int f, int w, int p, int s);

/*Task 6*/
int print_case_ptr(va_list *arg, int option, int f, int w, int p, int s);

/*Task 7*/
_flag_t *get_flags(void);
int handle_flags(const char *format, int *index, _flag_t *flags);

/*Task 8, 9, 11, 12*/
int handle_printing(const char *format, int *index, va_list *arg, _printf_case_t *cases, int f, int w, int p, int s);
int get_width(const char *format, int *index, va_list *arg);
int get_precision(const char *format, int *index, va_list *arg);
int get_size(const char *format, int *index);
int is_num(char c);

#endif
