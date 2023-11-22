#include "main.h"

/**
 * getwidth - gets field width for a conversion specifier.
 * @ap: variadic arguments of printf.
 * @f: pointer to the flags string.
 *
 * Return: if width is specified, width;
 * otherwise, 0;
 */
int getwidth(va_list ap, str_builder *f)
{
	int w = 0, end = f->len - 1;
	char *p, *dec_p = strchr(f->buffer, '.');

	if (f->len == 0)
		return (0);

	if (dec_p)
	{
		p = dec_p - 1;
		if (isnum(*p))
			w = *p - '0';
		else if (*p == '*')
			w = va_arg(ap, int);
	}
	else
	{
		p = f->buffer + end;
		if (isnum(*p))
			w = *p - '0';
		else if (*p == '*')
			w = va_arg(ap, int);
	}
	return (w);
}

/**
 * getprecision - gets precision for a conversion specifier.
 * @ap: variadic arguments of printf.
 * @f: pointer to the flags string.
 *
 * Return: if precision is specified, precision;
 * otherwise, 0;
 */
int getprecision(va_list ap, str_builder *f)
{
	int pr = 0, end = f->len - 1;
	char *p, *dec_p = strchr(f->buffer, '.');

	if (f->len == 0)
		return (0);

	if (dec_p)
	{
		p = dec_p + 1;
		if (p > (f->buffer + end))
			return (0);

		if (isnum(*p))
			pr = *p - '0';
		else if (*p == '*')
			pr = va_arg(ap, int);
	}
	return (pr);
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
