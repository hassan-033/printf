#include "main.h"

/**
 * handle_int - handles the %d and %i conversion specifier.
 * prints integer @n.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: nnmber of bytes written
 */
int handle_int(int n, str_builder *sb)
{
	return (write_int(n, sb));
}

/**
 * handle_uint - handles the %u conversion specifier.
 * prints unsigned integer @n.
 * @n: unsigned integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_uint(uint32_t n, str_builder *sb)
{
	return (write_int(n, sb));
}
