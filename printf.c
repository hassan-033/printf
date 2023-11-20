#include "main.h"

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
 * handle_specifier - handles output for different specifiers
 * @ap: variadic args list.
 * @ptr: the conversion specifier.
 * @buffer: pointer to the buffer.
 *
 * Return: Number of bytes written..
 */
int handle_specifier(va_list ap, char **ptr, str_builder *buffer)
{
	switch (**ptr)
	{
	case 'c':
		return (handle_char(va_arg(ap, int), buffer));
	case 's':
		return (handle_str(va_arg(ap, char *), buffer));
	case 'S':
		return (handle_npstr(va_arg(ap, char *), buffer));
	case '%':
		return (_write(buffer, "%", 1));
	case 'd':
	case 'i':
		return (handle_int(va_arg(ap, int), buffer));
	case 'u':
		return (handle_uint(va_arg(ap, uint32_t), buffer));
	case 'b':
		return (handle_bin(va_arg(ap, uint32_t), buffer));
	case 'o':
		return (handle_oct(va_arg(ap, uint32_t), buffer));
	case 'x':
	case 'X':
		return (handle_hex(va_arg(ap, uint32_t), buffer, isupper(*(*ptr))));
	case 'p':
		return (handle_ptr(va_arg(ap, void *), buffer));
	default:
		return (handle_default(ptr, buffer));
	}
}

/**
 * _printf - produces output according to format.
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
			temp = handle_specifier(ap, &ptr, &buffer);
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

