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
 * getflag - gets flag for a conversion specifier.
 * @percent_ptr: points to the % that begins a specifier.
 * @sb: pointer to the buffer.
 *
 * Return: if it finds a specifier, pointer to specifier;
 * otherwise, pointer to @percent_ptr;
 */
char *getflag(char *percent_ptr, str_builder *sb)
{
	char *start = percent_ptr + 1;
	int i = 0;

	sb_init(sb, MAX_FLAG_LEN);

	while (i < MAX_FLAG_LEN && *(start + i) != '\0')
	{
		if (strchr(SPECIFIERS, *(start + i)) != NULL)
			return (start + i);
		sb_append(sb, (start + i), 1);
		++i;
	}
	if (*(start + i) == '\0')
	{
		return (start);
	}
	if (strchr(SPECIFIERS, *(start + i)) != NULL)
		return (start + i);
	return (percent_ptr);
}

/**
 * handle_spec - handles output for different specifiers
 * @ap: variadic args list.
 * @ptr: ptr to ptr of the conversion specifier.
 * @buf: pointer to the buffer.
 * @f: pointer to the flags string
 *
 * Return: Number of bytes written..
 */
int handle_spec(va_list ap, char **ptr, str_builder *buf, str_builder *f)
{
	switch (**ptr)
	{
	case 'c':
		return (handle_char(va_arg(ap, int), buf));
	case 's':
		return (handle_str(va_arg(ap, char *), buf));
	case 'S':
		return (handle_npstr(va_arg(ap, char *), buf));
	case '%':
		return (_write(buf, "%", 1));
	case 'd':
	case 'i':
		return (do_int(ap, buf, f, *ptr));
	case 'u':
		return (do_uint(ap, buf, f, *ptr));
	case 'b':
		return (handle_bin(va_arg(ap, uint32_t), buf));
	case 'o':
		return (do_oct(ap, buf, f, *ptr));
	case 'x':
	case 'X':
		return (do_hex(ap, buf, f, *ptr));
	case 'p':
		return (handle_ptr(va_arg(ap, void *), buf));
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
	int bytes = 0, temp = 0;

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
			temp = handle_spec(ap, &ptr, &buffer, &flags);
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

