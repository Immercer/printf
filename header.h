#ifndef HEADER_H
#define HEARDER_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
char* (*get_func(char c))(va_list);
int _puts(char *str);

#endif /* end of HEADER_H */
