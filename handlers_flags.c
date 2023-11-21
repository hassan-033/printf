#include "main.h"
#define NUM_FLAGS "iudxXo"
#define HASH_FLAGS "xXo"
/**
 * handle_plus - handles the '+' flag for int specifiers.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_plus(int64_t n, str_builder *sb)
{
	if (n < 0)
		return (0);
	return (_write(sb, "+", 1));
}

/**
 * handle_space - handles the ' ' flag for int specifiers.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_space(int64_t n, str_builder *sb)
{
	if (n < 0)
		return (0);
	return (_write(sb, " ", 1));
}

/**
 * handle_hash - handles the '#' flag for int specifiers.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @spec: specifier identifier e.g 'd'
 *
 * Return: number of bytes written
 */
int handle_hash(int64_t n, str_builder *sb, char spec)
{
	if (n == 0)
		return (0);

	switch (spec)
	{
	case 'x':
		return (_write(sb, "0x", 2));
	case 'X':
		return (_write(sb, "0X", 2));
	case 'o':
		return (_write(sb, "0", 1));
	default:
		return (0);
	}
}

/**
 * handle_intflags - handles the flags for int specifiers.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @spec: specifier identifier e.g 'd'
 *
 * Return: number of bytes written
 */
int handle_intflags(int64_t n, str_builder *sb, str_builder *f, char spec)
{
	int b = 0;

	if (strchr(f->buffer, '+'))
		b += handle_plus(n, sb);
	else if (strchr(f->buffer, ' '))
		b += handle_space(n, sb);

	if (strchr(f->buffer, '#'))
		b += handle_hash(n, sb, spec);
	return (b);
}
