#include "main.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

/**
 */
int _putchar(int c);
int my_printf(const char *format, ...)
{
	int i;
	va_list list;
	va_start(list, format);

	i = 0;

	while (*format != '\0')
	{
		if(*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'u': /* unsigned int */
				{
					unsigned int u = va_arg(list, unsigned int);
					putchar(u);
					i++;
					break;
				}
				case 'o': /* octal */
				{
					unsigned int o = va_arg(list, unsigned int);
					putchar(o);
					i++;
					break;
				}
				case 'x': /* hexadecimal in lower case a-f */
				case 'X': /* HEXADECIMAL in UPPER CASE A-F */
				{
					unsigned int X = va_arg(list, unsigned int);
					putchar(X);
					i++;
					break;
				}
				default:
				{
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			format++;
		}
		format++;
	}
va_end(list);

return (i);
}
