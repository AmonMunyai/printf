#include "main.h"

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
		s = "(nil)";

	return (_puts(s));
}

/**
 * p_decimal - writes a base 10 number to stdout as a string
 * @args: variable argument list
 * Return: number of bytes in the string number
 */

int p_decimal(va_list args)
{
	int num, index, temp, len;
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

	free(nb);

	return (len);
}

/**
 * p_integer - writes number to stdout as string
 * @args: variable argument list
 * Return: number of bytes written to stdout
 */

int p_integer(va_list args)
{
	int len;

	len = p_decimal(args);

	return (len);
}

/**
 * get_p - selects the correct function to perform
 * @s: specifies the type of conversion to be applied
 * Return: pointer to function corresponding to conversion specifier
 */

int (*get_p(char s))(va_list)
{
	op_t ops[] = {
		{"c", p_char},
		{"s", p_string},
		{"d", p_decimal},
		{"i", p_integer},
		{NULL, NULL}
	};

	int index;

	for (index = 0; ops[index].s != NULL && *(ops[index].s) != s; index++)
		;

	return (ops[index].f);
}
