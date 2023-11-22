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
	len = _printf("%6d", 0);
	len2 = printf("%6d", 0);
fflush(stdout);
if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
len = _printf("%6d", 1024);
len2 = printf("%6d", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
len = _printf("In the middle %6d of a sentence.\n", 1024);
len2 = printf("In the middle %6d of a sentence.\n", 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
len = _printf("%6c", 'A');
len2 = printf("%6c", 'A');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("In the middle %6c of a sentence.\n", 'H');
	len2 = printf("In the middle %6c of a sentence.\n", 'H');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%6s", "Best School !\n");
	len2 = printf("%6s", "Best School !\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
len = _printf("%6s", "Hi!\n");
len2 = _printf("%6s", "Hi!\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
