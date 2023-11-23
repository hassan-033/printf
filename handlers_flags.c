#include "main.h"

/**
 * handle_plus_space - handles the ' '  & '+' flag for int specifiers.
 * @n: integer to be converted.
 * @sb: pointer to the buffer
 * @opt: 0 if to write '+', other nums if to write ' '
 *
 * Return: number of bytes written
 */
int handle_plus_space(int64_t n, str_builder *sb, int opt)
{
	if (n < 0)
		return (0);
	else if (opt == 0)
		return (_write(sb, "+", 1));
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
 * hyphen_zero_flag - gets whether the '-' or '0'
 * or none is set.
 * @w: width field for the specifier.
 * @f: pointer to the flags string.
 *
 * Return: 1 if hyphen is set, 2 if zero is set;
 * otherwise 0;
 */
int hyphen_zero_flag(int w, str_builder *f)
{
	int hzflag = 0, end; /* hyphen zero flag*/
	char *zf = strchr(f->buffer, '0');
	char *dec_p = strchr(f->buffer, '.');

	if (w == 0 || f->len == 0)
		return (0);

	if (strchr(f->buffer, '-'))
		hzflag = 1;
	else if (zf)
	{
		/*'0' positioned immediately before '.' OR positioned after '.' */
		if (dec_p && (zf > dec_p || zf + 1 == dec_p))
			return (0);

		if (dec_p && (dec_p - 1) > f->buffer)
			end = (dec_p - f->buffer) - 1;
		else
			end = f->len - 1;

		if (zf == f->buffer + end) /* if '0' is the last*/
			return (0);
		hzflag = 2;
	}
	return (hzflag);
}

/**
 * handle_intflags - handles the flags for int specifiers.
 * @n: integer to be converted.
 * @is_negative: whether @n is supposed to be negative.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @spec: specifier identifier e.g 'd'
 * @hzflag: width of the specifier
 * @cp: number of  '0' or ' ' width paddings
 * @zp: number of zero precision paddings
 *
 * Return: number of bytes written
 */
int handle_intflags(uint64_t n, int is_negative, str_builder *sb,
										str_builder *f, char spec, int hzflag, int cp, int zp)
{
	int b = 0;
	char c = ' ';

	if (cp > 0)
	{
		if (hzflag == 2)
		{
			c = '0';
			if (is_negative)
				b += _write(sb, "-", 1);
		}
		if (hzflag != 1)
			b += padding(sb, c, cp);
	}

	if (strchr(f->buffer, '+') && !is_negative)
		b += handle_plus_space(n, sb, 0);
	else if (strchr(f->buffer, ' ') && !is_negative)
		b += handle_plus_space(n, sb, 1);

	if (is_negative && hzflag != 2)
		b += _write(sb, "-", 1);
	if (strchr(f->buffer, '#'))
		b += handle_hash(n, sb, spec);

	if (zp > 0)
		b += padding(sb, '0', zp);
	return (b);
}

/**
 * handle_strflags - handles the flags for str specifiers.
 * @sb: pointer to the buffer
 * @hzflag: width of the specifier
 * @cp: number of ' ' width paddings
 *
 * Return: number of bytes written
 */
int handle_strflags(str_builder *sb, int hzflag, int cp)
{
	int b = 0;

	if (cp > 0 && hzflag == 0)
		b += padding(sb, ' ', cp);

	return (b);
}
