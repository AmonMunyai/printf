#include "main.h"

/**
 * p_rev - prints the reversed string
 * @args: variable argument list
 * Return: number of bytes printed to string
 */

int p_rev(va_list args)
{
	int index, len;
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(llun)";

	len = 0;
	for (index = _strlen(s); index > 0; index--)
	{
		_putchar(*(s + (index - 1)));
		len++;
	}

	return (len);
}
