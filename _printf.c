#include "main.h"

/**
 * _printf - writes output stdout according to a format
 * @format: output to write
 * Return: the number of characters printed
 * 	(excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int index, t_length;
	va_list args;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	if (format[0] == '%' && format[1] == '\0') /* % only */
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);

	va_start(args, format);

	for (index = 0, t_length = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] == '\0') /* % at end of string format */
				break;

			if (format[index] == '%')
			{
				t_length += _putchar('%');
				continue;
			}

			f = get_p(format[index]);

			t_length += (f == NULL) ?
				_printf("%%%c", format[index]) : f(args);
		}
		else
			t_length += _putchar(format[index]); /* write to stdout */
	}
	va_end(args);

	return (t_length);
}
