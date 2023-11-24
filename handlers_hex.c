#include "main.h"

/**
 * handle_hex - handles the %x & %X conversion specifier.
 * prints integer @n as hexadecimal (supports hex caps).
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @is_upper: print in uppercase
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: nubmer of bytes written
 */
int handle_hex(uint64_t n, str_builder *sb, str_builder *f,
							 int is_upper, int w, int p)
{
	int b = 0, hzflag = hyphen_zero_flag(w, f);
	char is_zero_p = (p == 0) && (strchr(f->buffer, '.') != NULL);
	int zp = int_precision_pads(n, 'x', p);
	int cp = int_align_pads(n, 0, 'x', w, p, zp);

	if (is_upper)
		b += handle_intflags(n, 0, sb, f, 'X', hzflag, cp, zp);
	else
		b += handle_intflags(n, 0, sb, f, 'x', hzflag, cp, zp);

	if (is_zero_p && n == 0 && w == 0)
		return (0);

	b += (is_zero_p && n == 0 && w != 0) ? 0 : write_hex(n, sb, is_upper, 1);
	if (cp > 0 && hzflag == 1)
	{
		if (strchr(f->buffer, '+') || strchr(f->buffer, ' '))
			--cp;
		b += padding(sb, ' ', cp);
	}

	return (b);
}

/**
 * handle_ptr - handles the %p conversion specifier.
 * prints memory address @n as hexadecimal (caps).
 * @n: address to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @w: width of the specifier
 *
 * Return: nubmer of bytes written
 */
int handle_ptr(void *n, str_builder *sb, str_builder *f, int w)
{
	int b = 0, zp = 0, hzflag = (f->len && strchr(f->buffer, '-')) ? 1 : 0;
	uint64_t tmp = (uint64_t) n;
	int d = (n == (void *) -1) ? 16 : 12;
	int cp = (zp > 0) ? w - zp : w - d;

	if (n == NULL)
		return (_write(sb, "(nil)", 5));

	cp -= 2; /* Accounting for 0x appendage */
	b += handle_intflags(tmp, 0, sb, f, 'p', hzflag, cp, zp);

	b += _write(sb, "0x", 2);
	if (n == (void *) -1)
		b += write_hex(tmp, sb, 0, 16);
	else
		b += write_hex(tmp, sb, 0, 12);
	if (cp > 0 && hzflag == 1)
		b += padding(sb, ' ', cp);

	return (b);
}
