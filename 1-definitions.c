#include "main.h"
/**
 * sel_func - chooses the right function to call
 *@c: symbol of the format specifier
 * Return: pointer to the chosen function.
 */

int (*sel_func(char c))(va_list pams)

{

	int i;

	fa k[] =
	{
		{'s', prntstr}, {'c', _putchar},
		{'b', prntbnry}, {'d', _prntnum},
		{'o', prntoct}, {'i', _prntnum},
		{'u', prnt_unsigned}, {'x', hex},
		{'X', hex0},{'S', cus_prntstr},
		{'\0', NULL}
	};

	i = 0;
	while (k[i].t != '\0')
	{
		if (k[i].t == c)
			return (k[i].fp);
		i++;
	}
	return (k[i].fp);
}

/**
 * countoct - counts the number of digits in a octal number
 *@n: decimal number passed.
 * Return: number of digits.
 */

int countoct(unsigned int n)
{
	if (n > 7)
	return (1 + countoct(n / 8));
	return (1);
}


/**
 * count_digits - counts the number of digits in a number
 *@n: the number whose digits are to be counted
 * Return: number of digits
 */

int count_digits(unsigned int n)
{

	if (n > 9)
	return (1 + count_digits(n / 10));
	return (1);
}

/**
 * countbnry - counts the number of digits in a binary number
 *@n: the decimal number whose digits in binary are to be counted
 * Return: number of digits.
 */

int countbnry(unsigned int n)
{
	if (n > 1)
	return (1 + countbnry(n / 2));
	return (1);
}


/**
 * prntoct - prints a number from va_list in octal
 *@pams: the va_list containing the number:
 * Return: the number of digits printed.
 */

int prntoct(va_list pams)
{
	int a = va_arg(pams, int);

	return (prntoct1(a));
}


