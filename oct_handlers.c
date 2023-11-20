#include "main.h"

/**
 * handle_oct - handles the %o conversion specifier.
 * prints integer @n as octal.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_oct(uint32_t n, str_builder *sb)
{
	write_oct(n, sb);
}
