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
