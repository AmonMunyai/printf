#include "main.h"

/**
 * p_char - writes a character to stdout
 * @args: variable argument list
 * Return: 1 (success), 0 otherwise
 */

int p_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * p_string - writes a string to stdout, without
 * its terminating null byte ('\0')
 * @args: variable argument list
 * Return: the length of the string written to stdout
 */

int p_string(va_list args)
{
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

	return (_puts(s));
}
