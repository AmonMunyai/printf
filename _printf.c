#include "main.h"
#include <stdio.h>

/**
 * _printf - writes output stdout according to a format
 * @format: output to write
 * Return: the number of characters printed
 *      (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int index;
	int t_length;
	va_list args;

	if (format == NULL)
		return (-1);

	index = 0;
	t_length = 0;
	va_start(args, format);

	while (format[index] != '\0')
	{
		/* handle % */
		if (format[index] == '%')
		{
			/* % at end of string format */
			if (format[index + 1] == '\0')
				break;

			/* double %'s */
			if (format[index + 1] == '%')
			{
				_putchar('%');
				index++;
				t_length++;
			}
			else
			{
				/* convert specifier */
				t_length += (*get_p(format[index + 1]))(args);
				index++;
			}
			index++;
		}
		/* write to stdout */
		_putchar(format[index++]);
		t_length++;
	}
	va_end(args);

	return (t_length);
}
