#include "main.h"
/**
 * _printf - function that produces output according to format
 * @...: parameter
 * @format: string
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
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char chara = va_arg(print, int);

				putchar(chara);
			}
			else if (*format == 's')
			{
				char *str = va_arg(print, char*);

				while (*str != '\0')
				{
					putchar(*str);
					str++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				chara_count++;
			}
		}
		format++;
	}
	va_end(print);
	return (chara_count);
}
