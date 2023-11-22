#include "main.h"

/**
 * handle_hex - handles the %x & %X conversion specifier.
 * prints integer @n as hexadecimal (supports hex caps).
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @is_upper: print in uppercase
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: nubmer of bytes written
 */
int handle_hex(uint64_t n, str_builder *sb, str_builder *f,
							 int is_upper, int w, int p)
{
	int b = 0;

	if (is_upper)
		b += handle_intflags(n, 0, sb, f, 'X', w, p);
	else
		b += handle_intflags(n, 0, sb, f, 'x', w, p);
	if (p > 0 || strchr(f->buffer, '.') == NULL)
		b += write_hex(n, sb, is_upper, 1);
	return (b);
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
