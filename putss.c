#include "main.h"
/**
 * putss - print a string
 *
 * @c: string
 * Return: no of bytes
 */
int putss(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			my_putchr(c[count]);
		}
	}
	return (count);
}

