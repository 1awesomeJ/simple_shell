#include "main.h"
/**
 * _putchar - prints a char from va_list argumnent
 *@pams: the va_list argument
 * Return: 1;
 */

int _putchar(va_list pams)
{
char c = va_arg(pams, int);
	write(1, &c, 1);
	return (1);
}

/**
 * prntstr - prints a string from va_list argument
 *@pams: the va_list argument
 * Return: number of digits printed
 */

int prntstr(va_list pams)
{
	char *s = va_arg(pams, char *);
	int i;

	if (s == NULL)
	s = "(null)";

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

/**
 * _putchar2 - prints a character
 *@c: the character to be printed
 * Return: 1
 */

int _putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 *
 *
 */

int prnt_unsigned(va_list pams)
{
	int a = va_arg(pams, int);

	return (prnt_unsigned1(a));
}

/**
 * prnt_unsigned1 - prints a number in binary
 *@a: the number to be printed.
 * Return: the number of digits printed.
 */

int prnt_unsigned1(int a)
{
	unsigned int k;
	k = a;
	if (k > 9)
	prnt_unsigned1(k / 10);
	_putchar2(k % 10 + '0');
	return (count_digits(k));
}
