#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_char : Prints characters
 * @ap : List of arguments
 * @count : Counter
 */
void print_char(va_list ap, int *count)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	(*count)++;
}

/**
 * print_int - prints integers
 * @ap: format identifier
 * @count: Count
 */
void print_int(va_list ap, int *count)
{
	int arg, len;
	char buffer[32];

	arg = va_arg(ap, int);
	len = sprintf(buffer, "%d", arg);
	write(1, buffer, len);
	(*count)++;
}

/**
 * print_string - Prints string
 * @ap: List of arguemnts
 * @count : counter
 */
void print_string(va_list ap, int *count)
{const char *str;
	int len;

	str = va_arg(ap, const char);
	len = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[len] != '\0')
		len++;
	write(1, str, len);
	(*count) += len;
}

/**
 * print_percent - Prints percent
 * @count : Counter
 */
void print_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
}
