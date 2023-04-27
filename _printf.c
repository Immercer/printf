#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int char_count = 0;
	int i = 0;

	va_list args;
	va_start(args, format);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				char_count++;
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);
				while (*s)
				{
					_putchar(*s);
					char_count++; s++;
				}
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				char_count++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
	}
	va_end(args);

	return (char_count);
}
