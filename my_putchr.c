#include "main.h"
/**
 * my_putchr - print a charcter
 * @c : char input
 * return: 1
 */
int my_putchr(char c)
{
	return (write(1, &c, 1));

}
