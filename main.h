#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* print functions.c module */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);  

/* printf.c module */
int _printf(const char *format, ...);

/* _puts.c module */
int _puts(char *str);
int _putchar(int c);

/* number.c module */
char *convert(long int num, int base, int flag, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* convert number module */
print_hex(va_list ap, params_t *params);
print_HEX(va_list ap, params_t *params);
print_binary(va_list ap, params_t *params);
print_octal(va_list ap, params_t *params);

#endif
