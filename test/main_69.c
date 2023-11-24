#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%06ld;%06li\n%06ld;%06li\n%06ld;%06li\n", LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, 0L, 0L);
	len2 = printf("%06ld;%06li\n%06ld;%06li\n%06ld;%06li\n", LONG_MAX, LONG_MAX, LONG_MIN, LONG_MIN, 0L, 0L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%06hd;%06hi\n%06hd;%06hi\n%06hd;%06hi\n", SHRT_MAX, SHRT_MAX, SHRT_MIN, SHRT_MIN, 0, 0);
	len2 = printf("%06hd;%06hi\n%06hd;%06hi\n%06hd;%06hi\n", SHRT_MAX, SHRT_MAX, SHRT_MIN, SHRT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%06ld;%06li\n%06ld;%06li\n", 98L, 98L, -98L, -98L);
	len2 = printf("%06ld;%06li\n%06ld;%06li\n", 98L, 98L, -98L, -98L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%06hd;%06hi\n%06hd;%06hi\n", 98, 98, -98, -98);
	len2 = printf("%06hd;%06hi\n%06hd;%06hi\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}