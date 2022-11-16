#include "main.h"
/**
 * _prntnum - prints a number from va_list argument
 *@pams: the va_list argument
 * Return: the number of digits printed
 */

int _prntnum(va_list pams)
{
	int n = va_arg(pams, int);

	return (_prntnum1(n));
}


/**
 * _prntnum1 - prints an integer in base 10
 *@n: the integer to be printed
 * Return: number of digits printed
 */

int _prntnum1(int n)
{
	unsigned int k;

	if (n < 0)
	{
	_putchar2('-');
	k = (n * -1);
	}
	else
	{
		k = n;
	}
	if (k > 9)
	_prntnum1(k / 10);
	_putchar2((k % 10) + '0');
	if (n >= 0)
	return (count_digits(k));
return (count_digits(k) + 1);
}

/**
 * prntbnry - prints a number from va_list in binary
 *@pams: the va_list to be printed
 * Return: number of digits printed.
 */

int prntbnry(va_list pams)
{
	int a = va_arg(pams, int);

	return (prntbnry1(a));
}

/**
 * prntbnry1 - prints a number in binary
 *@a: the number to be printed.
 * Return: the number of digits printed.
 */

int prntbnry1(int a)
{
	unsigned int k;

	k = a;
	if (k > 1)
	prntbnry1(k / 2);
	_putchar2(k % 2 + '0');
	return (countbnry(k));
}


/**
 * prntoct1 - prints a number in octal
 *@a: the number to be printed.
 * Return: the number of digits printed.
 */

int prntoct1(int a)
{
	unsigned int k;

	k = a;
	if (k > 7)
	prntoct1(k / 8);
	_putchar2(k % 8 + '0');
	return (countoct(k));
}
