#include "main.h"

/**
 * _printf - mini printf version
 * @format: initial string with all identifiers
 * Return: strings with identifiers expanded
 */
int _printf(const char *format, ...)
{
	int total_len = 0, i = 0, j = 0;
	va_list list;
	char *str;
	char* (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%') /* print character if not % */
		{
			_putchar(format[i]);
			i++;
			total_len++;
		}
		else /* if %, find function */
		{
			i++;
			if (format[i] == '\0') /* handle single ending % */
			{
				va_end(list);
				return (-1);
			}
			if (format[i] == '%') /* handle double %'s */
			{
				_putchar(format[i]);
				i++;
				total_len++;
			}
			else
			{
				f = get_func(format[i]); /* grab function */
				if (f == NULL)  /* handle fake id */
				{
					_putchar('%');
					_putchar(format[i]);
					i++;
					total_len += 2;
				}
				else /* return string, print */
				{
					str = f(list);
					if (str == NULL)
					{
						va_end(list);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						_putchar('\0');
						i++;
						total_len++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						_putchar(str[j]);
						j++;
						total_len++;
					}
					free(str);
				}
			}
		}
	}
	va_end(list);
	return (total_len);
}

