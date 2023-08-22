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
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field percision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign           : 1;
	unsigned int plus_flag        : 1;
	unsigned int space_flag       : 1;
	unsigned int hashtag_flag     : 1;
	unsigned int zero_flag        : 1;
	unsigned int minus_flag       : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier       : 1;
	unsigned int l_modifier       : 1;

} params_t;

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
int print_int(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

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
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

#endif
