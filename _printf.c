#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	int char_count = 0;
	int i = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				char_count++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);

				if (s != NULL)
				{
					while (*s)
					{
						_putchar(*s);
						char_count++;
						s++;
					}
				}
				else
				{
					_puts("(null)");
					char_count += 6;
				}
				i++;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int num = va_arg(args, int);
				char str[12];

				itoa(num, str);
				_puts(str);
				char_count += _strlen(str);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				char_count++;
				i++;
			}
			else
			{
				_putchar(format[i]);
				char_count++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
		i++;
	}
	va_end(args);

	return (char_count);
}
