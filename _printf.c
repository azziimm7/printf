#include "main.h"
/**
 * * _printf - print to stdout formatted text 
 *
 *  @format : format specifier
 *  return: no of bytes printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count, count = 0;

	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_putchr(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			my_putchr(va_arg(args, int));
			i++;
			 
		}
		else if (format[i + 1] == 's')
		{
			s_count = putss(va_arg(args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			my_putchr('%');
		}
		count += 1;

	}
	
	va_end(args);
	return (count);
}
