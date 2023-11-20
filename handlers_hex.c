#include "main.h"

/**
 * handle_hex - handles the %x & %X conversion specifier.
 * prints integer @n as hexadecimal (supports hex caps).
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @is_upper: print in uppercase
 *
 * Return: void
 */
void handle_hex(uint32_t n, str_builder *sb, int is_upper)
{
	write_hex(n, sb, is_upper);
}
