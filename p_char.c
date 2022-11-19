#include "main.h"

/**
 * p_char - writes a character to stdout
 * @args: variable argument list
 * Return: 1 (success)
 */

int p_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);

	return (1);
}
