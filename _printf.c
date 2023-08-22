#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _printf - function that produces output according to format
 * @...: parameter
 * @format: constant string
 * Return: number of characters printer
 */
int _printf(const char *format, ...)
{
	va_list print;
	int chara_count = 0;

	va_start(print, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			chara_count++;
		}
		else if (*format == '%')
		{
			format++;
		}
		if (*format == 'c')
		{
			char chara = va_arg(print, int);

			putchar(chara);
			chara_count++;
		}
		format++;
	}
	va_end(print);
	return (chara_count);
}
