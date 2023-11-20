#include "main.h"

/**
 * sb_init - initialize a string builder.
 * @sb: the pointer to sb to initialize.
 * @capacity: size of the string builder.
 *
 * Return: 0 if successful;
 * Otherwise, stops process.
 */
int sb_init(str_builder *sb, int capacity)
{
	sb->buffer = (char *) malloc(capacity);

	if (sb->buffer == NULL)
		exit(EXIT_FAILURE);

	sb->buffer[0] = '\0';
	sb->len = 0;
	sb->cap = capacity;

	return (EXIT_SUCCESS);
}

/**
 * sb_append - appends to a string builder.
 * @sb: the pointer to sb to append to.
 * @s: str to append.
 * @n: no of chars to append from @s
 *
 * Return: Nothing...
 */
void sb_append(str_builder *sb, char *s, int n)
{
	sb->len += n;
	strncat(sb->buffer, s, n);
}

/**
 * sb_clean - cleans up a string builder.
 * @sb: the pointer to sb to clean up.
 *
 * Return: Nothing...
 */
void sb_clean(str_builder *sb)
{
	free(sb->buffer);
}

/**
 * sb_is_full - tells a string builder buffer is full.
 * @sb: the pointer to sb to check.
 * @len: expected len of string to add.
 *
 * Return: 1 if full;
 * otherwise 0.
 */
int sb_is_full(str_builder *sb, int len)
{
	return ((sb->len + len + 1 > sb->cap) ? 1 : 0);
}
