#include <stdio.h>
#include <stdarg.h>

/**
 * _printf -function that produces output according to format 
 * @...: parameter
 * @format: constant string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list print;
	int i = 0;
	char chara;
	char *str;

	va_start(print, format);

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (*format == '%')
		{
			if (*format == 'c')
			{
				chara = va_arg(print, int);
				putchar(chara);
			}
			else if (*format == 's')
			{
				str = va_arg(print, char*);
				putchar(str[i]);
				i++;
			}
		}
	}
	va_end(print);
	return (format[i]);
}

