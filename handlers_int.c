#include "main.h"

/**
 * handle_int - handles the %d and %i conversion specifier.
 * prints integer @n.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: nnmber of bytes written
 */
int handle_int(int64_t n, str_builder *sb, str_builder *f, int w, int p)
{
	int b = 0, hzflag = hyphen_zero_flag(w, f);
	uint64_t tmp = n;
	int is_negative = n < 0;
	int cp = int_align_pads(n, is_negative, 'd', w, p);

	if (is_negative) /* handle INT_MIN overflow */
	{
		tmp = (n / -10);
		tmp *= 10;
	}
	b += handle_intflags(tmp, is_negative, sb, f, 'd', w, p);
	if (p > 0 || strchr(f->buffer, '.') == NULL)
	{
		b += write_int(n, sb);

		if (cp > 0 && hzflag == 1)
			b += padding(sb, ' ', cp);
	}
	return (b);
}

/**
 * handle_uint - handles the %u conversion specifier.
 * prints unsigned integer @n.
 * @n: unsigned integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: number of bytes written
 */
int handle_uint(uint64_t n, str_builder *sb, str_builder *f, int w, int p)
{
	int b = 0, hzflag = hyphen_zero_flag(w, f);
	int cp = int_align_pads(n, 0, 'u', w, p);

	b += handle_intflags(n, 0, sb, f, 'u', w, p);
	if (p > 0 || strchr(f->buffer, '.') == NULL)
	{
		b += write_uint(n, sb);

		if (cp > 0 && hzflag == 1)
			b += padding(sb, ' ', cp);
	}
	return (b);
}
