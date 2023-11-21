#include "main.h"

/**
 * handle_int - handles the %d and %i conversion specifier.
 * prints integer @n.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 *
 * Return: nnmber of bytes written
 */
int handle_int(int n, str_builder *sb, str_builder *f)
{
	int b = 0;

	b += handle_intflags(n, sb, f, 'd');
	b += write_int(n, sb);
	return (b);
}

/**
 * handle_uint - handles the %u conversion specifier.
 * prints unsigned integer @n.
 * @n: unsigned integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 *
 * Return: number of bytes written
 */
int handle_uint(uint32_t n, str_builder *sb, str_builder *f)
{
	int b = 0;

	b += handle_intflags(n, sb, f, 'u');
	b += write_int(n, sb);
	return (b);
}
