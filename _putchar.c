#include <unistd.h>

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
