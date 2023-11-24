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
	int b = 0, hzflag = hyphen_zero_flag(w, f);
	char is_zero_p = (p == 0) && (strchr(f->buffer, '.') != NULL);
	int zp = int_precision_pads(n, 'o', p);
	int cp = int_align_pads(n, 0, is_zero_p, 'o', w, zp);

	b += handle_intflags(n, 0, sb, f, 'o', hzflag, cp, zp);
	if (is_zero_p && n == 0 && w == 0)
		return (0);

	if (!(is_zero_p && n == 0 && w != 0))
	{
		if (n == 0)
			b += _write(sb, "0", 1);
		else
			b += write_oct(n, sb);
	}

	if (cp > 0 && hzflag == 1)
	{
		if (strchr(f->buffer, '+') || strchr(f->buffer, ' '))
			--cp;
		b += padding(sb, ' ', cp);
	}

	return (b);
}
