#include "main.h"

/**
 * cus_prntstr - prints a string from va_list argument
 *@pams: the va_list argument
 * Return: number of digits printed
 */

int cus_prntstr(va_list pams)
{
	char *s = va_arg(pams, char *);
	int i, j;
	char *a;
	char c = '0';

	a = "\\x";

	if (s == NULL)
		s = "(null)";

	i = 0;
	j = 0;
	while (s[i])
	{
		if((s[i] < 32) || (s[i] >= 127))
		{
			while(a[j])
			{
				_putchar2(a[j]);
				j++;
			}
			if (s[i] < 16)
			{
				j += _putchar2(c);
				i += hex2(s[i]);
			continue;
			}
				j += hex2(s[i]);
				i++;
			continue;
		}
		write(1, &s[i], 1);
		i++;
	}
	if (j)
		return (j + i);
	else
		return (i);
}
