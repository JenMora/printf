#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - produce output as per format
 * putchar - functtion description
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
					putchar(c);
					printed_chars++;
					break;
				}
				case 's':
				{
					char *s = va_arg(list, char *);

					while (*s != '\0')
					{
						putchar(*s);
						s++;
						printed_chars++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					printed_chars++;
					break;
				}
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
		       	printed_chars++;
		}
		format++;
	}
	va_end(list);

	return (printed_chars);
}
