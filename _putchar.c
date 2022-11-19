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
