#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_char - prints a character
 * @val: the argument list passed in.
 *
 * Return: 1, the character length.
 */
int printf_char(va_list val)
{
	int value = va_arg(val, int);

	_putchar(value);
	return (1);
}

/**
 * printf_string - prints a string as arg to the printf
 * @val: the argument list passed in.
 *
 * Return: the length of the string.
 */
int printf_string(va_list val)
{
	char *value = va_arg(val, char *);
	int i = 0;

	while (value[i] != '\0')
	{
		_putchar(value[i]);
		i++;
	}
	return (i);
}
/**
 * printf_37 - prints the % character
 *
 * Return: 1, which is the length of %;
 */
int printf_37(void)
{
	_putchar(37);
	return (1);
}
