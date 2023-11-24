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

	len = _printf("%*ld;%*li\n%*ld;%*li\n%*ld;%*li\n", 6, LONG_MAX, 6, LONG_MAX, 6, LONG_MIN, 6, LONG_MIN, 6, 0L, 6, 0L);
	len2 = printf("%*ld;%*li\n%*ld;%*li\n%*ld;%*li\n", 6, LONG_MAX, 6, LONG_MAX, 6, LONG_MIN, 6, LONG_MIN, 6, 0L, 6, 0L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*hd;%*hi\n%*hd;%*hi\n%*hd;%*hi\n", 6, SHRT_MAX, 6, SHRT_MAX, 6, SHRT_MIN, 6, SHRT_MIN, 6, 0, 6, 0);
	len2 = printf("%*hd;%*hi\n%*hd;%*hi\n%*hd;%*hi\n", 6, SHRT_MAX, 6, SHRT_MAX, 6, SHRT_MIN, 6, SHRT_MIN, 6, 0, 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*ld;%*li\n%*ld;%*li\n", 6, 98L, 6, 98L, 6, -98L, 6, -98L);
	len2 = printf("%*ld;%*li\n%*ld;%*li\n", 6, 98L, 6, 98L, 6, -98L, 6, -98L);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%*hd;%*hi\n%*hd;%*hi\n", 6, 98, 6, 98, 6, -98, 6, -98);
	len2 = printf("%*hd;%*hi\n%*hd;%*hi\n", 6, 98, 6, 98, 6, -98, 6, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}