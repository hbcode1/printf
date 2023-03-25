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
int _putchar(char);
void print_s(char *);
void print_i_d(int);
int num_len(unsigned int n);
#endif /* end def main.h */
