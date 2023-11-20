#include "main.h"

/**
 * handle_int - handles the %d and %i conversion specifier.
 * prints integer @n.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_int(int n, str_builder *sb)
{
	write_int(n, sb);
}

/**
 * handle_uint - handles the %u conversion specifier.
 * prints unsigned integer @n.
 * @n: unsigned integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_uint(uint32_t n, str_builder *sb)
{
	write_int(n, sb);
}
