#include "main.h"

/**
 * do_int - wrapper function for handle_int with diff int sizes.
 * prints integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 *
 * Return: nnmber of bytes written
 */
int do_int(va_list ap, str_builder *sb, str_builder *f, char *p)
{
		if (*(p - 1) == 'h')
			return (handle_int((short) va_arg(ap, int), sb, f));
		else if (*(p - 1) == 'l')
			return (handle_int(va_arg(ap, long), sb, f));
		return (handle_int(va_arg(ap, int), sb, f));
}

/**
 * do_uint - wrapper function for handle_uint with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 *
 * Return: number of bytes written
 */
int do_uint(va_list ap, str_builder *sb, str_builder *f, char *p)
{
		if (*(p - 1) == 'h')
			return (handle_uint((short) va_arg(ap, uint32_t), sb, f));
		else if (*(p - 1) == 'l')
			return (handle_uint(va_arg(ap, uint64_t), sb, f));
		return (handle_uint(va_arg(ap, uint32_t), sb, f));
}

/**
 * do_oct - wrapper function for handle_oct with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 *
 * Return: number of bytes written
 */
int do_oct(va_list ap, str_builder *sb, str_builder *f, char *p)
{
		if (*(p - 1) == 'h')
			return (handle_oct((short) va_arg(ap, int), sb, f));
		else if (*(p - 1) == 'l')
			return (handle_oct(va_arg(ap, long), sb, f));
		return (handle_oct(va_arg(ap, int), sb, f));
}

/**
 * do_hex - wrapper function for handle_hex with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 *
 * Return: number of bytes written
 */
int do_hex(va_list ap, str_builder *sb, str_builder *f, char *p)
{
		if (*(p - 1) == 'h')
			return (handle_hex((short) va_arg(ap, uint32_t), sb, f, isupper(*p)));
		else if (*(p - 1) == 'l')
			return (handle_hex(va_arg(ap, uint64_t), sb, f, isupper(*p)));
		return (handle_hex(va_arg(ap, uint32_t), sb, f, isupper(*p)));
}
