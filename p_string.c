#include "main.h"

/**
 * p_string - writes a string to stdout, without
 * its terminating null byte ('\0')
 * @args: variable argument list
 * Return: length of string
 */

int p_string(va_list args)
{
	int i;
	char *s;

	i = 0;
	s = va_arg(args, char *);

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}
