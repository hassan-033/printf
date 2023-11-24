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

	len = _printf("%d;%i\n%S\n%d;%i\n", INT_MAX, INT_MAX, "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x10", INT_MIN, INT_MIN);
	len2 = printf("%d;%i\n\\x01\\x02\\x03\\x04\\x05\\x06\\x07\\x08\\x09\\x0A\\x10\n%d;%i\n", INT_MAX, INT_MAX, INT_MIN, INT_MIN);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
