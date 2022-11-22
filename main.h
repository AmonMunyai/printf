#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/* main function */
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

/* print functions  */
int p_char(va_list args);
int p_string(va_list args);
int p_stringS(va_list args);
int p_rev(va_list args);
int p_rot13(va_list args);

int print_number(int num, int base, char *buffer);
int p_decimal(va_list args);
int p_integer(va_list args);
int p_binary(va_list args);

int (*get_p(char s))(va_list);

/* helper functions */
int _putchar(char c);
int _puts(const char *s);
int _strlen(const char *s);

#endif /* MAIN_H */
