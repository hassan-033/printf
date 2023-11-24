#include "main.h"

/**
 * isnum - check whether a char is a number.
 * @c: The char to check.
 *
 * Return: if it is a num, 1;
 * otherwise, 0;
 */
int isnum(char c)
{
	return (c > 47 && c < 58);
}

/**
 * digits - gets the number of digits of a number
 * whether decimal, hex, or oct.
 * @n: integer to count its digits.
 * @spec: the conversion specifier.
 *
 * Return: number of digits depending on specifier;
 */
int digits(int64_t n, char spec)
{
	int d = 0, div;

	if (n == 0)
		return (1);

	switch (spec)
	{
		case 'x':
		case 'X':
			div = 16;
			break;
		case 'o':
			div = 8;
			break;
		default:
			div = 10;
			break;
	}
	while (n != 0)
	{
		d++;
		n /= div;
	}
	return (d);
}

/**
 * padding - writes character a specified number of
 * times to a buffer.
 * @sb: pointer to the buffer
 * @c: char used to pad buffer.
 * @count: lengyh of the padding.
 *
 * Return: Numbr of bytes padded;
 */
int padding(str_builder *sb, char c, int count)
{
	int b = 0;

	if (count == 0)
		return (0);

	while (count--)
		b += _write(sb, &c, 1);

	return (b);
}

/**
 * int_align_pads - get number of pads for width alignment
 * @n: the integer to convert
 * @is_negative: whether the integer is supposed to be negative.
 * @is_zero_p: whether precision is specified to be 0.
 * @spec: the specifier.
 * @w: width.
 * @zp: int precision pads (zero padding).
 *
 * Return: Numbr of pads needed for alignment;
 */
int int_align_pads(uint64_t n, int is_negative, int is_zero_p,
									 char spec, int w, int zp)
{
	int d = digits(n, spec);
	int cp; /* char padding */

	if (is_zero_p && n == 0)
		return (w);

	cp = (zp > 0) ? w - (zp + d) : w - d;
	cp -= is_negative;
	return (cp);
}

/**
 * int_precision_pads - get number of pads for precision.
 * @n: the integer to convert
 * @spec: the specifier.
 * @p: precision.
 *
 * Return: Numbr of pads needed for precision;
 */
int int_precision_pads(uint64_t n, char spec, int p)
{
	int d = digits(n, spec);

	return (p - d);
}
