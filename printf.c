#include "main.h"

/**
 * _write - performs buffered writes to stdout.
 * writes @s if s is not NULL, otherwise writes
 * remaining content in buffer to stdout.
 * @sb: pointer to the buffer.
 * @s: the str to write.
 * @s_len: the len of str to write.
 *
 * Return: Nothing..
 */
void _write(str_builder *sb, char *s, int s_len)
{
	if (s == NULL) /* condition to write buffer to stdout */
	{
		write(1, sb->buffer, sb->len);
		sb_clean(sb);
	}
	else if (sb_is_full(sb, s_len)) /* write buffer to stdout if buffer is full */
	{
		write(1, sb->buffer, sb->len);
		sb_clean(sb);
		sb_init(sb, BUFFER_SIZE);
		sb_append(sb, s, s_len);
	}
	else /* write to buffer */
	{
		sb_append(sb, s, s_len);
	}
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
		return (percent_ptr);
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
 * Return: Nothing..
 */
void handle_specifier(va_list ap, char *ptr, str_builder *buffer)
{
	switch (*ptr)
	{
	case 'c':
		handle_char(va_arg(ap, int), buffer);
		break;
	case 's':
		handle_str(va_arg(ap, char *), buffer);
		break;
	case 'S':
		handle_npstr(va_arg(ap, char *), buffer);
		break;
	case '%':
		_write(buffer, "%", 1);
		break;
	case 'd':
	case 'i':
		handle_int(va_arg(ap, int), buffer);
		break;
	case 'u':
		handle_uint(va_arg(ap, uint32_t), buffer);
		break;
	case 'b':
		handle_bin(va_arg(ap, uint32_t), buffer);
		break;
	case 'o':
		handle_oct(va_arg(ap, uint32_t), buffer);
		break;
	case 'x':
	case 'X':
		handle_hex(va_arg(ap, uint32_t), buffer, isupper(*ptr));
		break;
	}
}

/**
 * _printf - produces output according to format.
 * @format: str containing characters, specifiers, flags etc.
 *
 * Return: Length of printed chars.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	str_builder buffer, flags;
	char *ptr;

	ptr = (char *) format;
	sb_init(&buffer, BUFFER_SIZE);
	va_start(ap, format);
	printf("Buff len %d: \n", buffer.len);
	fflush(stdout);

	while (*ptr)
	{
		if (*ptr != '%')
		{
			_write(&buffer, ptr, 1);
		}
		else
		{
			printf("I entered else\n");
			fflush(stdout);
			ptr = getflag(ptr, &flags);
			printf("Case: %c\n", *ptr);
			fflush(stdout);
			handle_specifier(ap, ptr, &buffer);
		}
		++ptr;
	}
	_write(&buffer, NULL, 0); /* write buffer to stdout */
	va_end(ap);
	return (0);
}

