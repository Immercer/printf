#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
char* (*get_func(char c))(va_list);
int _puts(char *str);
int _strlen(char *str);
void reverse(char *str);    
void itoa(int num, char *str);

#endif /* end of MAIN_H */
