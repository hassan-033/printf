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
	int b = 0, cp, zp, hzflag = hyphen_zero_flag(w, f);
	uint64_t tmp = n;
	int is_negative = n < 0;
	char is_zero_p = (p == 0) && (strchr(f->buffer, '.') != NULL);

	if (is_negative) /* handle INT_MIN overflow */
	{
		tmp = (n / -10);
		tmp *= 10;
	}
	zp = int_precision_pads(tmp, 'd', p);
	cp = int_align_pads(tmp, is_negative, is_zero_p, 'd', w, zp);

	b += handle_intflags(tmp, is_negative, sb, f, 'd', hzflag, cp, zp);

	if (is_zero_p && n == 0 && w == 0)
		return (0);

	b += (is_zero_p && n == 0 && w != 0) ? 0 : write_int(n, sb);
	if (cp > 0 && hzflag == 1)
	{
		if ((strchr(f->buffer, '+') || strchr(f->buffer, ' ')) && !is_negative)
			--cp;
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
	char is_zero_p = (p == 0) && (strchr(f->buffer, '.') != NULL);
	int zp = int_precision_pads(n, 'u', p);
	int cp = int_align_pads(n, 0, is_zero_p, 'u', w, zp);

	b += handle_intflags(n, 0, sb, f, 'u', hzflag, cp, zp);

	if (is_zero_p && n == 0 && w == 0)
		return (0);

	b += (is_zero_p && n == 0 && w != 0) ? 0 : write_uint(n, sb);
	if (cp > 0 && hzflag == 1)
	{
		if (strchr(f->buffer, '+') || strchr(f->buffer, ' '))
			--cp;
		b += padding(sb, ' ', cp);
	}

	return (b);
}
