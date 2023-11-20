#include "main.h"

/**
 * handle_bin - handles the %b conversion specifier.
 * prints integer @n as binary.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_bin(uint32_t n, str_builder *sb)
{
	write_bin(n, sb);
}
