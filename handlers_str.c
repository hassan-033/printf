#include "main.h"

/**
 * handle_char - handles the %c conversion specifier.
 * prints character @c.
 * @c: pointer to the character to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_char(char c, str_builder *sb)
{
	_write(sb, &c, 1);
}

/**
 * handle_npstr - handles the %S conversion specifier.
 * prints string @s (non-printable characters print as '|x<hex>')
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_npstr(char *s, str_builder *sb)
{
	int s_len = strlen(s);
	int i = 0;
	char c;

	while (i < s_len)
	{
		if ((*(s + 1) > 0  && *(s + i) < 32) || *(s + i) >= 127)
		{
			c = *(s + i);
			(c < 16) ? _write(sb, "\\x0", 3) : _write(sb, "\\x", 2);
			write_hex(c, sb, 1);
		}
		else
			_write(sb, s + i, 1);
		i++;
	}
}

/**
 * handle_str - handles the %s conversion specifier.
 * prints string @s.
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 *
 * Return: void
 */
void handle_str(char *s, str_builder *sb)
{
	int s_len = strlen(s);

	_write(sb, s, s_len);
}
