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
			switch(format[i])
			{
				case 'c':
				{
					char c = va_arg(args, int);
					_putchar(c);
					char_count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					while (*s)
					{
						_putchar(*s);
						char_count++; s++; 
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					char_count++;
					break;
				}
			}	
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
	}
	va_end(args);

	return char_count;
	
}

