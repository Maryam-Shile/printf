#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include "helper_functions.h"

int _printf(const char *format, ...);
void print_char(va_list ap, int *count);
void print_int(va_list ap, int *count);
void print_string(va_list ap, int *count);
void print_percent(int *count);
void handle_format_specifier(char specifier, va_list ap, int *count);

#endif /* MAIN_H */
