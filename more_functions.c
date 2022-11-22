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

/**
 * p_rot13 - prints the rot 13'ed string
 * @args: variable argument list
 * Return: number of bytes printed to string
 */

int p_rot13(va_list args)
{
	int index, len;
	char *s, c;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";

	len = 0;
	for (index = 0; *(s + index) != '\0'; index++)
	{
		if (
				(*(s + index) >= 'A' &&
				*(s + index) <= 'M') ||
				(*(s + index) >= 'a' &&
				 *(s + index) <= 'm'))
		{
			c = *(s + index) + 13;
		}

		if (
				(*(s + index) >= 'N' &&
				 *(s + index) <= 'Z') ||
				(*(s + index) >= 'n' &&
				 *(s + index) <= 'z'))
		{
			c = *(s + index) - 13;
		}
		_putchar(c);
		len++;
	}

	return (len);
}
