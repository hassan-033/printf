#include "main.h"

/**
 * handle_oct - handles the %o conversion specifier.
 * prints integer @n as octal.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_oct(uint32_t n, str_builder *sb)
{
	if (n == 0)
		return (_write(sb, "0", 1));
	return (write_oct(n, sb));
}
