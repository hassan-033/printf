#include "main.h"

/**
 * handle_oct - handles the %o conversion specifier.
 * prints integer @n as octal.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 *
 * Return: number of bytes written
 */
int handle_oct(uint32_t n, str_builder *sb, str_builder *f)
{
	int b = 0;

	b += handle_intflags(n, sb, f, 'o');
	if (n == 0)
	{
		b += _write(sb, "0", 1);
		return (b);
	}
	b += write_oct(n, sb);
	return (b);
}
