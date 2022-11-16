#include "main.h"
/**
 * _printf- prints anything in C!
 *@format: format of the things to be printed
 * Return: number of characters printed.
 */


int _printf(const char *format, ...)
{
	int i, k;
	va_list pams;
	int (*func)(va_list);

	if (format == NULL || (*(format) == '%' && *(format + 1) == '\0'))
		return (-1);
	va_start(pams, format);
	i = 0;
	k = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{		func = sel_func(format[i + 1]);
			if (func != NULL)
			{	k += func(pams);
				i += 2;
				continue;
			}
			else
			{
				if (format[i + 1] == '%')
				{	k += _putchar2(format[i + 1]);
					i += 2;
					continue;
				}
				else
				{	k += _putchar2(format[i]);
					k += _putchar2(format[i + 1]);
					i += 2;
					continue;
				}
			}
		}
		k += _putchar2(format[i]);
		i++;
	}
	va_end(pams);
	return (k);
}
