#include "main.h"
#include <stdio.h>

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

/**
 * p_stringS - writes a string to stdout, without
 * its terminating null byte ('\0')
 * @args: variable argument list
 * Return: the length of the string written to stdout
 */

int p_stringS(va_list args)
{
	char *s;
	int index;
	int len;


	s = va_arg(args, char *);
	if (s == NULL)
	{
		s = "(null)";
		return (_puts(s));
	}

	for (index = 0, len = 0; *(s + index) != '\0'; index++)
	{
		if ((*(s + index) > 0 && *(s + index) < 32) || *(s + index) >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			if (*(s + index) < 16)
			{
				_putchar('0');
				len++;
			}

			len += print_number(*(s + index), 16, "0123456789ABCDEF");
		}
		else
		{
			_putchar(*(s + index));
			len++;
		}
	}

	return (len);
}
