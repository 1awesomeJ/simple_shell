#include "main.h"
/**
 * hex0 - prints number in uppercase hexamdecimal from va_list
 *@pams: the va_list from which the number is extracted.
 * Return: number of digits printed.
 */



int hex0(va_list pams)
{
	int n = va_arg(pams, int);

	return (hex2(n));

}

/**
 * hex - prints number in lowercase hexamdecimal from va_list
 *@pams: the va_list from which the number is extracted.
 * Return: number of digits printed.
 */

int hex(va_list pams)
{
	int n = va_arg(pams, int);

	return (hex1(n));

}


/**
 * hex1 - prints number in lowercase hexamdecimal from a base 10 int.
 *@a: the base 10 integer.
 * Return: number of digits printed.
 */
int hex1(int a)
{
	unsigned int k;
	char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	k = a;
	if (k > 15)
	hex1(k / 16);
	_putchar2(arr[k % 16]);
	return (count_hex(k));
}

/**
 * hex2 - prints number in UPPERcase hexamdecimal from a base 10 int.
 *@a: the base 10 integer.
 * Return: number of digits printed.
 */

int hex2(int a)
{
	unsigned int k;
	char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	k = a;
	if (k > 15)
	hex2(k / 16);
	_putchar2(arr[k % 16]);
	return (count_hex(k));
}


int count_hex(unsigned int n)
{
	if (n > 15)
	return (1 + count_hex(n / 16));
	return (1);
}

