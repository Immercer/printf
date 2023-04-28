#include <unistd.h>
#include "main.h"
/**
 * _putchar - print a character to standard output
 * @c: target character
 * Return: character
 */ 

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 *
 * Return: the number of characters printed
 */
int _puts(char *str)
{
    int len = 0;

    while (*str)
    {
        len += write(1, str, 1);
        str++;
    }

    return len;
}

int _strlen(char *str)
{
	int count  = 0;

	while (*str)
	{
		str++; count++;
	}
	return (count);
}

void itoa(int num, char *str)
{
	int sign = 1;
	int i = 0;

	if (num < 0)
	{
		str[i++] = sign = -1;
		num = -num;
	}
	
	while (num)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	
	if (sign < 0)
		str[i++] = '-';
	
	str[i] = '\0';

	reverse(str);
}

void reverse(char *str)
{
	int i = 0;
	int j = _strlen(str) - 1;
	
	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j++;
	}
}
