#include "main.h"
#include <stdint.h>

/**
 * _write - performs buffered writes to stdout.
 * writes @s if s is not NULL, otherwise writes
 * remaining content in buffer to stdout.
 * @sb: pointer to the buffer.
 * @s: the str to write.
 * @s_len: the len of str to write.
 *
 * Return: the amount of bytes written.
 */
int _write(str_builder *sb, char *s, int s_len)
{
	int bytes = 0;

	if (s == NULL) /* condition to write buffer to stdout */
	{
		bytes = write(1, sb->buffer, sb->len);
		sb_clean(sb);
	}
	else if (sb_is_full(sb, s_len)) /* write buffer to stdout if buffer is full */
	{
		bytes = write(1, sb->buffer, sb->len);
		sb_clean(sb);
		sb_init(sb, BUFFER_SIZE);
		sb_append(sb, s, s_len);
	}
	else /* write to buffer */
	{
		sb_append(sb, s, s_len);
	}
	return (bytes);
}

/**
 * handle_spec - handles output for different specifiers
 * @ap: variadic args list.
 * @ptr: ptr to ptr of the conversion specifier.
 * @buf: pointer to the buffer.
 * @f: pointer to the flags string
 * @w: the width for specifier.
 * @p: the precision for specifier.
 *
 * Return: Number of bytes written..
 */
int handle_spec(va_list ap, char **ptr, str_builder *buf,
								str_builder *f,	int w, int p)
{
	switch (**ptr)
	{
	case 'c':
		return (handle_char(va_arg(ap, int), buf, f, w));
	case 's':
		return (handle_str(va_arg(ap, char *), buf, f, w, p));
	case 'S':
		return (handle_npstr(va_arg(ap, char *), buf));
	case 'r':
		return (handle_revstr(va_arg(ap, char *), buf));
	case 'R':
		return (handle_rot13(va_arg(ap, char *), buf));
	case '%':
		return (_write(buf, "%", 1));
	case 'd':
	case 'i':
		return (do_int(ap, buf, f, *ptr, w, p));
	case 'u':
		return (do_uint(ap, buf, f, *ptr, w, p));
	case 'b':
		return (handle_bin(va_arg(ap, uint32_t), buf));
	case 'o':
		return (do_oct(ap, buf, f, *ptr, w, p));
	case 'x':
	case 'X':
		return (do_hex(ap, buf, f, *ptr, w, p));
	case 'p':
		return (handle_ptr(va_arg(ap, void *), buf, f, w));
	default:
		return (handle_default(ptr, buf));
	}
}

/**
 * _printf - formatted output conversion.
 * produces output according to a format.
 * @format: str containing characters, specifiers, flags etc.
 *
 * Return: Length of printed chars;
 * -1 if @format is NULL.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	str_builder buffer, flags;
	char *ptr;
	int w, p, bytes = 0, temp = 0;

	ptr = (char *) format;
	if (ptr == NULL)
		return (-1);
	sb_init(&buffer, BUFFER_SIZE);
	va_start(ap, format);

	while (*ptr)
	{
		if (*ptr != '%')
		{
			bytes += _write(&buffer, ptr, 1);
		}
		else
		{
			ptr = getflag(ptr, &flags);
			w = getwidth(ap, &flags);
			p = getprecision(ap, &flags);
			temp = handle_spec(ap, &ptr, &buffer, &flags, w, p);
			if (temp < 0)
			{
				_write(&buffer, NULL, 0);
				sb_clean(&flags);
				return (temp);
			}
			bytes += temp;
			sb_clean(&flags);
		}
		++ptr;
	}
	bytes += _write(&buffer, NULL, 0); /* write buffer to stdout */
	va_end(ap);
	return (bytes);
}

