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

	len = _printf("%.*d%.*i\n", 6, 1024, 6, 1024);
	len2 = printf("%.*d%.*i\n", 6, 1024, 6, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.*d%.*i\n", 6, 102498402, 6, 102498402);
	len2 = printf("%.*d%.*i\n", 6, 102498402, 6, 102498402);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.*d%.*i\n", 0, 1024, 0, 1024);
	len2 = printf("%.*d%.*i\n", 0, 1024, 0, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}