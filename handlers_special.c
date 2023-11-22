#include "main.h"
#include <strings.h>

/**
 * handle_rot13 - handles the %R conversion specifier.
 * prints string @s encoding in rot13.
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written.
 */
int handle_rot13(char *s, str_builder *sb)
{
	int b = 0, i = 0;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *j, c;

	while (*(s + i++))
	{
		j = strchr(alpha, *(s + i));
		if (j != NULL)
			c = rot[j - alpha];
		else
			c = *(s + i);
		b += _write(sb, &c, 1);
	}
	return (b);
}

/**
 * handle_revstr - handles the %r conversion specifier.
 * prints string @s in reverse.
 * @s: pointer to the string to be converted.
 * @sb: pointer to the buffer
 *
 * Return: number of bytes written
 */
int handle_revstr(char *s, str_builder *sb)
{
	int s_len;
	int b = 0;

	s_len = strlen(s);
	
	while(--s_len >= 0)
		b += _write(sb, (s + s_len), 1);

	return (b);
}

