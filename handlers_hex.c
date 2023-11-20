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
	return (write_hex(n, sb, is_upper, 1));
}

/**
 * handle_ptr - handles the %p conversion specifier.
 * prints memory address @n as hexadecimal (caps).
 * @n: address to be converted.
 * @sb: pointer to the buffer
 *
 * Return: nubmer of bytes written
 */
int handle_ptr(void *n, str_builder *sb)
{
	int b;

	if (n == NULL)
		return (_write(sb, "(nil)", 5));

	b = _write(sb, "0x", 2);
	if (n == (void *) -1)
		b += write_hex((uint64_t) n, sb, 0, 16);
	else
		b += write_hex((uint64_t) n, sb, 0, 12);
	return (b);
}
