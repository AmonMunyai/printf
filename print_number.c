#include "main.h"

/**
 * print_number - prints a number
 * @num: integer to print
 * @base: base number to print
 * @buffer: character buffers to print
 * Return: number of bytes printed
 */

int print_number(int num, int base, char *buffer)
{
	int index, len;
	char *str_n;
	unsigned int temp;

	str_n = malloc(sizeof(*str_n) * 1024);
	if (str_n == NULL)
		return (-1);

	index = 0, len = 0;
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
		len++;
	}

	if (num == 0)
	{
		str_n[0] = '0';
		str_n[1] = '\0';
	}
	else
	{
		for (index = 0, temp = (unsigned int) num; temp > 0; index++)
		{
			str_n[index] = buffer[temp % base];
			temp /= base;
		}
		str_n[index] = '\0';
	}

	for (index = _strlen(str_n); index > 0; index--)
	{
		_putchar(str_n[index - 1]);
		len++;
	}
	free(str_n);

	return (len);
}

/**
 * p_decimal - writes a number to stdout
 * @args: variable argument list
 * Return: number of bytes in the string number
 */

int p_decimal(va_list args)
{
	int n, len;

	n = va_arg(args, int);
	len = print_number(n, 10, "0123456789");

	return (len);
}

/**
 * p_integer - writes number to stdout
 * @args: variable argument list
 * Return: number of bytes written to stdout
 */

int p_integer(va_list args)
{
	int n, len;

	n = va_arg(args, int);
	len = print_number(n, 10, "0123456789");

	return (len);
}

/**
 * p_binary - writes number to stdout as binary
 * @args: variable argument list
 * Return: number of bytes written to stdout
 */

int p_binary(va_list args)
{
	int n, len;

	n = va_arg(args, int);
	len = print_number(n, 2, "01");

	return (len);
}
