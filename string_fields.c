#include "main.h"

/**
 * get_percision - gets percesion from format string
 * @p: format string
 * @params: the paramteres sturct
 * @ap: the arg pointer
 *
 * Return: new pointer
 */
char *get_percision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
