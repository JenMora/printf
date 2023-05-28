#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - produce output as per format
 * _putchar - functtion description
 * @c: parameter
 * Return: Num of characters printed
 * includes '\0' byte used at the end of strings
 */

int _putchar(int c);

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;

	va_start(list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(list, int);

					printed_chars += putchar(c);
					break;
				}
				case 's':
				{
					char *s = va_arg(list, char *);

					while (*s != '\0')
					{
						printed_chars += putchar(*s);
						s++;
					}
					break;
				}
				case '%':
				{
					printed_chars += putchar('%');
					break;
				}
				default:
					break;
			}
		}
		else
		{
		printed_chars += putchar(*format);
		}
		format++;
	}
	va_end(list);

	return (printed_chars);
}
