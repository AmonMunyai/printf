#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: character to write to stdout
 * Return: non-negative number on success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout, without
 * its terminating null byte '\0'
 * @s: string to write
 * Return: the length of the string written to stdout
 */

int _puts(const char *s)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
	{
		_putchar(s[index]);
	}

	return (index);
}

/**
 * _strlen - calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0')
 * @s: points to string to calculate length of
 * Return: the number of characters in the string s
 */

int _strlen(const char *s)
{
	int index;

	for (index = 0; *(s + index) != '\0'; index++)
		;

	return (index);
}
