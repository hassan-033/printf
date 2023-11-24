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

	len = _printf("%.*u;%.*u;%.*u\n", 6, 1024, 6, 1024984020, 0, 1024);
	len2 = printf("%.*u;%.*u;%.*u\n", 6, 1024, 6, 1024984020, 0, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.*o;%.*o;%.*o\n", 6, 1024, 6, 1024984020, 0, 1024);
	len2 = printf("%.*o;%.*o;%.*o\n", 6, 1024, 6, 1024984020, 0, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.*x;%.*x;%.*x\n", 6, 1024, 6, 1024984020, 0, 1024);
	len2 = printf("%.*x;%.*x;%.*x\n", 6, 1024, 6, 1024984020, 0, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.*X;%.*X;%.*X\n", 6, 1024, 6, 1024984020, 0, 1024);
	len2 = printf("%.*X;%.*X;%.*X\n", 6, 1024, 6, 1024984020, 0, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}