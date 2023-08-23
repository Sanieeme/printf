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
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			chara_count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char chara = va_arg(print, int);

				putchar(chara);
				chara_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(print, char*);

				while (*str != '\0')
				{
					putchar(*str);
					chara_count++;
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
