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

	len = _printf("%+*d;%+*i\n%+*d;%+*i\n%+*d;%+*i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	len2 = printf("%+*d;%+*i\n%+*d;%+*i\n%+*d;%+*i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% *d;% *i\n% *d;% *i\n% *d;% *i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	len2 = printf("% *d;% *i\n% *d;% *i\n% *d;% *i\n", 6, INT_MAX, 6, INT_MAX, 6, INT_MIN, 6, INT_MIN, 6, 0, 6, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%+*d;%+*i\n%+*d;%+*i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	len2 = printf("%+*d;%+*i\n%+*d;%+*i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% *d;% *i\n% *d;% *i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	len2 = printf("% *d;% *i\n% *d;% *i\n", 6, 98, 6, 98, 6, -98, 6, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}