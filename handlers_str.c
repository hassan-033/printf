#include "main.h"

/**
 * handle_char - handles the %c conversion specifier.
 * prints character @c.
 * @c: pointer to the character to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string
 * @w: width of the specifier
 *
 * Return: number of bytes written.
 */
int handle_char(char c, str_builder *sb, str_builder *f, int w)
{
	int b = 0, cp = w - 1, hzflag = hyphen_zero_flag(w, f);

	b += handle_strflags(sb, hzflag, cp);
	b += _write(sb, &c, 1);
	if (cp > 0 && hzflag == 1)
		b += padding(sb, ' ', cp);

	return (b);
}

/**
 * handle_npstr - handles the %S conversion specifier.
 * prints string @s (non-printable characters print as '|x<hex>')
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written.
 */
int handle_npstr(char *s, str_builder *sb)
{
	int s_len = strlen(s);
	int i = 0, b = 0;
	char c;

	while (i < s_len)
	{
		if ((*(s + i) > 0  && *(s + i) < 32) || *(s + i) >= 127)
		{
			c = *(s + i);
			b += _write(sb, "\\x", 2);
			b += write_hex(c, sb, 1, 2);
		}
		else
		{
			b += _write(sb, s + i, 1);
		}
		i++;
	}
	return (b);
}

/**
 * handle_str - handles the %s conversion specifier.
 * prints string @s.
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 * @f: pointer to the flags string.
 * @w: width of the specifier
 * @p: precision of the specifier
 *
 * Return: number of bytes written
 */
int handle_str(char *s, str_builder *sb, str_builder *f, int w, int p)
{
	int b = 0, cp = w - (p + strlen(s));
	int s_len, hzflag = hyphen_zero_flag(w, f);

	if (s == 0)
		s = "(null)";

	b += handle_strflags(sb, hzflag, cp);
	s_len = strlen(s);
	if (p > 0 || strchr(f->buffer, '.') == NULL)
	{
		if (p > 0 && s_len > p)
			s_len = p;
		while (s_len > 1024)
		{
			b += (_write(sb, s, 1024));
			s_len -= 1024;
			s += 1024;
		}
		b += (_write(sb, s, s_len));
		if (cp > 0 && hzflag == 1)
			b += padding(sb, ' ', cp);
	}
	return (b);
}

/**
 * handle_default - handles the wrong conversion specifier.
 * @ptr: pointer to pointer of start of string.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_default(char **ptr, str_builder *sb)
{
	int b = 0, l = strlen(*ptr);

	if (l == 0 || (l == 1 && **ptr == ' '))
	{
		(*ptr)--;
		return (-1);
	}
	else
	{
		b += _write(sb, "%", 1);
		if (**ptr != 'h' && **ptr != 'l')
			b += _write(sb, *ptr, 1);
		return (b);
	}
}
