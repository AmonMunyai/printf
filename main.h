#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);

/**
 * struct p - Struct p
 * @s: the conversion specifier
 * @f: the function associated
 */

typedef struct p
{
        char *s;
        int (*f)(va_list);
} op_t;

int p_char(va_list args);
int p_string(va_list args);
int p_decimal(va_list args);
int p_integer(va_list args);

int p_nil(va_list args);

int (*get_p(char s))(va_list);

int _strlen(const char *s);

#endif /* MAIN_H */
