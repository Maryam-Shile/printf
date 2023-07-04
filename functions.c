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
	int num = va_arg(ap, int);
	int i, temp, len = 0;
	char num_str[12];

	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		(*count)++;
	}
	temp = num;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	num_str[len] = '\0';
	for (i = len - 1; i >= 0; i--)
	{
		num_str[i] = num % 10 + '0';
		num /= 10;
	}
	write(1, num_str, len);
	(*count) += len;
}

/**
 * print_string - Prints string
 * @ap: List of arguemnts
 * @count : counter
 */
void print_string(va_list ap, int *count)
{
	const char *str;
	int len;

	str = va_arg(ap, const char*);
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
