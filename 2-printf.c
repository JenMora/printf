#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 *@_printf:prints strings in binary form
 *
 *@format: the string of char
 *
 * Return: 0
 */
void print_binary(unsigned int value)
{
	    if (value > 1)
		            print_binary(value / 2);

	        putchar('0' + (value % 2));
}

int my_printf(const char *format, ...)
{
	int chars_printed = 0;
	/* to keep track of the character count*/
	char b;
	/*the storage of the character to be processed*/
	unsigned int binary_value;
	/*to store the binary conversion*/

	va_list list;

	va_start(list, format);

	while ((b = *format++))
	{
		if (b == '%')
		{
			switch (*format++)
			{
				case 'b':
					binary_value = va_arg(list, unsigned int);
					printf("%b", binary_value);
					chars_printed += sizeof(unsigned int) * 8;
					/*coverts bytes to bits*/
					break;
				case '\0':
					return (chars_printed);
				default:
					putchar(b);
					chars_printed++;
					break;
			}
		}
		else
		{
			putchar(b);
			chars_printed++;
		}
	}
	va_end(list);

	return (chars_printed);
}
