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
	int i;
	int c;
	va_list list;

	i = 0;
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
					c = va_arg(list, int);
					putchar(c);
					i++;
					break;
				}
				case 's':
				{
					char *s = va_arg(list, char *);

					while (*s != '\0')
					{
						putchar(*s);
						s++;
						i++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					i++;
					break;
				}
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			i++;
		}
		format++;
	}
	va_end(list);

	return (i);
}
