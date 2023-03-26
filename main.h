#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * u_i: typedef for unsigned int
 */
typedef unsigned int u_i;
/**
 * u_c: typedef for unsigned char
 */
typedef unsigned char u_c;

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
