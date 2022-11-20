#include "main.h"

/**
 * _printf - writes output stdout according to a format
 * @format: output to write
 * Return: the number of characters printed
 * 	(excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int i, j;
	int len;
	va_list args;
	conv_t f_spec[] = {
		{"c", p_char},
		{"s", p_string},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	i = 0;
	len = 0;
	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			if (format[i] == '%') /* for double %'s */
			{
				len++;
			}

			while (f_spec[j].spec != NULL)
			{
				if (format[i] == f_spec[j].spec[0])
					break;
				j++;
			}
			if (j < 3)
				len += f_spec[j].f(args);
		}
		else
		{
			_putchar(format[i]); /* write character to stdout */
			len++;
		}
		i++;
	}

	va_end(args);

	return (len);
}
