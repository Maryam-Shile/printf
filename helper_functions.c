#include "main.h"
#include "main.h"
#include "helper_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_format_specifier - helper function
 * @specifier : Specifier
 * @ap : List
 * @count : Counter
 */
void handle_format_specifier(char specifier, va_list ap, int *count)
{
	switch (specifier)
	{
		case 'c':
			print_char(ap, count);
			break;
		case 's':
			print_string(ap, count);
			break;
		case 'd':
		case 'i':
			print_int(ap, count);
			break;
		case '%':
			print_percent(count);
			break;
		default:
			write(1, &specifier, 1);
			specifier--;
			write(1, &specifier, 1);
			count += 2;
			break;
	}
}
