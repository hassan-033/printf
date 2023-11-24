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

	len = _printf("%s%r%c", "Show me the string: ", "! loohcS tseB", '\n');
	len2 = printf("%sBest School !%c", "Show me the string: ", '\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%s%r%c", "Show me the string: ", "!loohcS tseB", '\n');
	len2 = printf("%sBest School!%c", "Show me the string: ", '\n');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
