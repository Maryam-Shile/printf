#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - The function produces out according to a format
 * @format: Character string to print
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count, i;

	count = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break;
			handle_format_specifier(format[i], ap, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
