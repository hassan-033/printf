#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, 6, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%6.*d;%6.*i\n%6.*d;%6.*i\n%6.*d;%6.*i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	len2 = printf("%6.*d;%6.*i\n%6.*d;%6.*i\n%6.*d;%6.*i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.*d;%6.*i\n%6.*d;%6.*i\n%6.*d;%6.*i\n", 0, INT_MAX, 0, INT_MAX, 0, INT_MIN, 0, INT_MIN, 0, 0, 0, 0);
	len2 = printf("%6.*d;%6.*i\n%6.*d;%6.*i\n%6.*d;%6.*i\n", 0, INT_MAX, 0, INT_MAX, 0, INT_MIN, 0, INT_MIN, 0, 0, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.*d;%6.*i\n%6.*d;%6.*i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	len2 = printf("%6.*d;%6.*i\n%6.*d;%6.*i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6.*d;%6.*i\n%6.*d;%6.*i\n", 0, 98, 0, 98, 0, -98, 0, -98);
	len2 = printf("%6.*d;%6.*i\n%6.*d;%6.*i\n", 0, 98, 0, 98, 0, -98, 0, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}