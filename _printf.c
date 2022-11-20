#include "main.h"

/**
 * convert_specifier - writes output to stdout according to specifier
 * @specifier: specifies the type of conversion to be applied
 * @args: variable argument list
 * @t_length: pointer to int
 * Return: the number of characters printed
 */

int convert_specifier(const char specifier, va_list args, int *t_length)
{
	int length, temp;

	length = 0, temp = 0;

	if (specifier == '%') /* handle double %'s */
		length += _putchar(specifier);

	else
	{
		temp = (*get_p(specifier))(args);
		if (temp == 0) /* handle invalid id's */
			temp += _putchar('%');

		length += temp;
	}
	*(t_length) += length;

	return (length);
}

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
		if (format[index] != '%')
			t_length += _putchar(format[index]); /* write to stdout */
		else
		{
			index++;
			if (format[index] == '\0') /* % at end of string format */
				break;

			convert_specifier(format[index], args, &t_length);
		}
	}
	va_end(args);

	return (t_length);
}
