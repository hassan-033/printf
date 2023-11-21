#include "main.h"

/**
 * write_int - writes an integer to stdout (buffered).
 * @n: the integer to print.
 * @sb: pointer to the buffer.
 *
 * Return: number of bytes written.
 */
int write_int(int64_t n, str_builder *sb)
{
	int64_t dup = n;
	int64_t div = 1;
	char c;
	int bytes = 0;


	if (n == 0)
	{
		c = '0';
		bytes += _write(sb, &c, 1);
		return (bytes);
	}
	while (dup / 10 != 0)
	{
		div *= 10;
		dup /= 10;
	}

	if (n < 0)
	{
		c = '-';
		bytes += _write(sb, &c, 1);
		n *= -1;
	}

	while (n != 0)
	{
		c = (n / div) + 48;
		bytes += _write(sb, &c, 1);
		n %= div;
		div /= 10;
	}

	while (div != 0)
	{
		bytes += _write(sb, "0", 1);
		div /= 10;
	}
	return (bytes);
}

/**
 * write_uint - writes an unsigned integer to stdout (buffered).
 * @n: the unsigned integer to print.
 * @sb: pointer to the buffer.
 *
 * Return: number of bytes written
 */
int write_uint(uint64_t n, str_builder *sb)
{
	uint64_t dup = n;
	uint64_t div = 1;
	char c;
	int bytes = 0;


	if (n == 0)
	{
		c = '0';
		bytes += _write(sb, &c, 1);
		return (bytes);
	}
	while (dup / 10 != 0)
	{
		div *= 10;
		dup /= 10;
	}

	while (n != 0)
	{
		c = (n / div) + 48;
		bytes += _write(sb, &c, 1);
		n %= div;
		div /= 10;
	}

	while (div != 0)
	{
		bytes += _write(sb, "0", 1);
		div /= 10;
	}
	return (bytes);
}

/**
 * write_bin - writes an integer as binary
 * to stdout (buffered).
 * @n: the integer to write as binary.
 * @sb: pointer to the buffer.
 *
 * Return: number of bytes written.
 */
int write_bin(uint64_t n, str_builder *sb)
{
	char c;
	int bytes;

	if (n == 0)
		return (0);
	bytes = write_bin(n / 2, sb);

	c = (n % 2) + '0';
	return (bytes + _write(sb, &c, 1));
}

/**
 * write_oct - writes an integer as octal
 * to stdout (buffered).
 * @n: the integer to write as octal.
 * @sb: pointer to the buffer.
 *
 * Return: number of bytes written
 */
int write_oct(uint64_t n, str_builder *sb)
{
	char c;
	int bytes;

	if (n == 0)
		return (0);
	bytes = write_oct(n / 8, sb);

	c = (n % 8) + '0';
	return (bytes + _write(sb, &c, 1));
}

/**
 * write_hex - writes an integer as hexadecimal
 * to stdout (buffered).
 * @n: the integer to write as hexadecimal.
 * @sb: pointer to the buffer.
 * @is_upper: whether to write in uppercase.
 * @w: speciifies width (shorts are padded with 0).
 *
 * Return: number of bytes written
 */
int write_hex(uint64_t n, str_builder *sb, int is_upper, int w)
{
	char c;
	int bytes;

	if (n == 0 && w <= 0)
		return (0);

	bytes = write_hex(n / 16, sb, is_upper, w - 1);

	c = (n % 16) + '0';
	if (c > '9')
	{
		c = is_upper ? c + 7 : c + 39;
	}
	return (bytes + _write(sb, &c, 1));
}
