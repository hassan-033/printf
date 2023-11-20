#include "main.h"

/**
 * handle_hex - handles the %x & %X conversion specifier.
 * prints integer @n as hexadecimal (supports hex caps).
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @is_upper: print in uppercase
 *
 * Return: nubmer of bytes written
 */
int handle_hex(uint32_t n, str_builder *sb, int is_upper)
{
	if (n == 0)
		return (_write(sb, "0", 1));
	return (write_hex(n, sb, is_upper, 0));
}

/**
 * handle_ptr - handles the %p conversion specifier.
 * prints memory address @n as hexadecimal (caps).
 * @n: address to be converted.
 * @sb: pointer to the buffer
 *
 * Return: nubmer of bytes written
 */
int handle_ptr(uint64_t n, str_builder *sb)
{
	if (n == 0)
		return (_write(sb, "0", 1));
	return (write_hex(n, sb, 1, 16));
}
