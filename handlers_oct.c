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
	int cp = int_align_pads(n, 0, 'o', w, p);

	b += handle_intflags(n, 0, sb, f, 'o', w, p);
	if (n == 0)
	{
		b += _write(sb, "0", 1);
		return (b);
	}
	if (p > 0 || strchr(f->buffer, '.') == NULL)
	{
		b += write_oct(n, sb);
		
		if (cp > 0 && hzflag == 1)
			b += padding(sb, ' ', cp);
	}
	return (b);
}
