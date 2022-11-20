#include "main.h"

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
		{NULL, p_nil}
	};

	int index;

	for (index = 0; ops[index].s != NULL && *(ops[index].s) != s; index++)
		;

	return (ops[index].f);
}
