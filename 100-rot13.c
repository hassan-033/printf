/**
 * rot13 - encodes a string using rot13.
 * @p: The character to be checked.
 *
 * Return: 1 if upper, otherwise 0;
 */
char *rot13(char *p)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i;
	char *str = p;

	while (*str)
	{
		for (i = 0; i < 52; i++)
		{
			if (*str == alpha[i])
			{
				*str = rot[i];
				break;
			}
		}
		str++;
	}

	return (p);
}


