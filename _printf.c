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
	int index, t_length;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (index = 0, t_length = 0; format[index] != '\0'; index++)
	{
		/* handle % */
		if (format[index] != '%')
		{
			_putchar(format[index]); /* write to stdout */
			t_length++;
		}
		else
		{
			index++;
			if (format[index] == '\0') /* % at end of string format */
				break;

			if (format[index] == '%') /* double %'s */
			{
				_putchar(format[index]);
				t_length++;
			}
			else
			{
				/* convert specifier */
				t_length += (*get_p(format[index]))(args);
			}
		}
	}
	va_end(args);

	return (t_length);
}
