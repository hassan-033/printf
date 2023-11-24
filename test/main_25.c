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

	len = _printf("%.6d%.6i\n", 1024, 1024);
	len2 = printf("%.6d%.6i\n", 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.6d%.6i\n", 102498402, 102498402);
	len2 = printf("%.6d%.6i\n", 102498402, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.0d%.0i\n", 1024, 1024);
	len2 = printf("%.0d%.0i\n", 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.d%.i\n", 1024, 1024);
	len2 = printf("%.d%.i\n", 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
