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

	len = _printf("%.6u;%.6u;%.0u;%.u\n", 1024, 1024984020, 1024, 1024);
	len2 = printf("%.6u;%.6u;%.0u;%.u\n", 1024, 1024984020, 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.6o;%.6o;%.0o;%.o\n", 1024, 1024984020, 1024, 1024);
	len2 = printf("%.6o;%.6o;%.0o;%.o\n", 1024, 1024984020, 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.6x;%.6x;%.0x;%.x\n", 1024, 1024984020, 1024, 1024);
	len2 = printf("%.6x;%.6x;%.0x;%.x\n", 1024, 1024984020, 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%.6X;%.6X;%.0X;%.X\n", 1024, 1024984020, 1024, 1024);
	len2 = printf("%.6X;%.6X;%.0X;%.X\n", 1024, 1024984020, 1024, 1024);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}