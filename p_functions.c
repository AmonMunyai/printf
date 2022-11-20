#include "main.h"
#include <stdio.h>

/**
 * p_char - writes a character to stdout
 * @args: variable argument list
 * Return: 1 (success), 0 otherwise
 */

int p_char(va_list args)
{
	char c;

	c = va_arg(args, int);

	if (c == '\0' || c == 0)
		return (0);
	_putchar(c);

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
	int index;
	char *s;

	index = 0;
	s = va_arg(args, char *);

	while (s[index] != '\0')
	{
		_putchar(s[index]);
		index++;
	}

	return (index);
}

/**
 * p_decimal - writes a base 10 number to stdout as string
 * @args: variable argument list
 * Return: number of bytes in string number
 */

int p_decimal(va_list args)
{
	int num;
	int index;
	int temp;
	int len;
	char *nb;

	nb = malloc(sizeof(*nb) * 1024);
	if (nb == NULL)
		return (-1);

	index = 0;
	len = 0;
	num = va_arg(args, int);

	/* handle negative numbers */
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
		len++;
	}

	/* convert num to string */
	for (index = 0, temp = num; temp > 0; index++)
	{
		nb[index] = (temp % 10) + '0'; /* get last digit */
		temp = temp / 10; /* remove last digit */
	}
	nb[index] = '\0';

	/* write number to stdout */
	for (index = _strlen(nb); index >  0; index--)
	{
		_putchar(nb[index - 1]);
		len++;
	}

	return (len);
}

/**
 * p_integer - writes number to stdout as string
 * @args: variable argument list
 * Return: number of bytes written to stdout
 */

int p_integer(va_list args)
{
	int num;
	int len;

	len = 0;
	num = va_arg(args, int);

	/* handle negative numbers */
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
		len++;
	}

	return (len);
}

/**
 * p_nil - handles invalid id's
 * @args: variable argument list
 * Return: always 0
 */

int p_nil(va_list args __attribute__((unused)))
{
	return (0);
}
