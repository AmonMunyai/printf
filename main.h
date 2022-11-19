#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> /* for testing */

#include <stdarg.h> /* va_list */
#include <stdlib.h> /* NULL */

int _putchar(char c);
int _printf(const char *format, ...);

int p_char(va_list args);
int p_string(va_list args);

/**
 * struct conv - holds conversion specifier,
 * and corresponding function
 * @spec: conversion specifier
 * @f: pointer to function correspending with
 * conversion specifier
 */

typedef struct conv
{
	char *spec;
	int (*f)(va_list);
} conv_t;

#endif /* MAIN_H */
