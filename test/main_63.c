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

	len = _printf("%+06d;%+06i\n%+06d;%+06i\n%+06d;%+06i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	len2 = printf("%+06d;%+06i\n%+06d;%+06i\n%+06d;%+06i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 06d;% 06i\n% 06d;% 06i\n% 06d;% 06i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	len2 = printf("% 06d;% 06i\n% 06d;% 06i\n% 06d;% 06i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN, 0, 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%+06d;%+06i\n%+06d;%+06i\n", 98, 98, -98, -98);
	len2 = printf("%+06d;%+06i\n%+06d;%+06i\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% 06d;% 06i\n% 06d;% 06i\n", 98, 98, -98, -98);
	len2 = printf("% 06d;% 06i\n% 06d;% 06i\n", 98, 98, -98, -98);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}