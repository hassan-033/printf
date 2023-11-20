#include "main.h"

/**
 * handle_bin - handles the %b conversion specifier.
 * prints integer @n as binary.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_bin(uint32_t n, str_builder *sb)
{
	return (write_bin(n, sb));
}
