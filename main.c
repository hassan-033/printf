#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%zz");
	len2 = printf("%zz");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ. %d, %d\n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
