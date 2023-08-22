#include "main.h"

/**
 * _printf -function that produces output according to format 
 * @...: parameter
 * @format: constant string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list print;
    int i, char_count = 0;

    va_start(print, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == 'd' || format[i] == 'i')
            {
                int num = va_arg(print, int);
                char_count += printf("%d", num);
            }
            else if (format[i] == 'c')
            {
                int chara = va_arg(print, int);
                putchar(chara);
                char_count++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(print, char*);
                while (*str != '\0')
                {
                    putchar(*str);
                    char_count++;
                    str++;
                }
            }
            else if (format[i] == '%')
            {
                putchar('%');
                char_count++;
            }
        }
        else
        {
            putchar(format[i]);
            char_count++;
        }
    }

    va_end(print);
    return char_count;
}
