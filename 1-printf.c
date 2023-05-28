#include "main.h"
#include <stdio.h>
#include <stdarg.h>


int _putchar(int c);
int my1_printf(const char *format, ...)
{
	int i;
	va_list list;
	va_start(list, format);

	i = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
		
			switch (*format)
			{
				case 'd':
				case 'i':
				{
					int n =va_arg(list, int);
					putchar(n);
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
