#include "main.h"

/**
 * main - check code
 * Return: 0 (success)
 */

int main(void)
{
	char *name = "John Smith";
	int len, len2;

	_printf("Char [%c]\n", 'B');
	printf("Char [%c]\n", 'B');

	len = _printf("String [%s]\n", name);
	len2 = printf("String [%s]\n", name);

	printf("_printf[%d] <-> printf[%d]\n", len, len2);

	return (0);
}
