#include "main.h"

/**
 * do_int - wrapper function for handle_int with diff int sizes.
 * prints integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 * @w: width of the specifier
 * @pr: precision of the specifier
 *
 * Return: nnmber of bytes written
 */
int do_int(va_list ap, str_builder *sb, str_builder *f, char *p, int w, int pr)
{
	if (*(p - 1) == 'h')
		return (handle_int((short) va_arg(ap, int), sb, f, w, pr));
	else if (*(p - 1) == 'l')
		return (handle_int(va_arg(ap, long), sb, f, w, pr));
	return (handle_int(va_arg(ap, int), sb, f, w, pr));
}

/**
 * do_uint - wrapper function for handle_uint with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 * @w: width of the specifier
 * @pr: precision of the specifier
 *
 * Return: number of bytes written
 */
int do_uint(va_list ap, str_builder *sb, str_builder *f, char *p,
		int w, int pr)
{
	if (*(p - 1) == 'h')
		return (handle_uint((uint16_t) va_arg(ap, uint32_t), sb, f, w, pr));
	else if (*(p - 1) == 'l')
		return (handle_uint(va_arg(ap, uint64_t), sb, f, w, pr));
	return (handle_uint(va_arg(ap, uint32_t), sb, f, w, pr));
}

/**
 * do_oct - wrapper function for handle_oct with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 * @w: width of the specifier
 * @pr: precision of the specifier
 *
 * Return: number of bytes written
 */
int do_oct(va_list ap, str_builder *sb, str_builder *f, char *p, int w, int pr)
{
	if (*(p - 1) == 'h')
		return (handle_oct((uint16_t) va_arg(ap, uint32_t), sb, f, w, pr));
	else if (*(p - 1) == 'l')
		return (handle_oct(va_arg(ap, uint64_t), sb, f, w, pr));
	return (handle_oct(va_arg(ap, uint32_t), sb, f, w, pr));
}

/**
 * do_hex - wrapper function for handle_hex with diff int sizes.
 * prints unsigned integer @n.
 * @ap: variadic arguments to printf list
 * @sb: pointer to the sbfer
 * @f: pointer to the flags string
 * @p: pointer to the specifier.
 * @w: width of the specifier
 * @pr: precision of the specifier
 *
 * Return: number of bytes written
 */
int do_hex(va_list ap, str_builder *sb, str_builder *f, char *p, int w, int pr)
{
	if (*(p - 1) == 'h')
		return (handle_hex((uint16_t) va_arg(ap, uint32_t), sb, f, isupper(*p),
										 w, pr));
	else if (*(p - 1) == 'l')
		return (handle_hex(va_arg(ap, uint64_t), sb, f, isupper(*p), w, pr));
	return (handle_hex(va_arg(ap, uint32_t), sb, f, isupper(*p), w, pr));
}
