#include "main.h"

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
