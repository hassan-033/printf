#include "main.h"

/**
 * handle_oct - handles the %o conversion specifier.
 * prints integer @n as octal.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: number of bytes written
 */
int handle_oct(uint64_t n, str_builder *sb, str_builder *f, int w, int p)
{
	int b = 0;

	b += handle_intflags(n, 0, sb, f, 'o', w, p);
	if (n == 0)
	{
		b += _write(sb, "0", 1);
		return (b);
	}
	if (strchr(f->buffer, '.') == NULL)
		b += write_oct(n, sb);
	return (b);
}
