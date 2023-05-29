#include "main.h"


/**
 * print_buffer - a function that produces output according to format
 * @buffer: the collection of characters
 * @buff_ind: element of array depending on char length
 * Return: the printed characters from string
 *
 * Authors: Magdaline N. and Jeniffer Moraa
 */

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0, flags, width, precision;
	int size, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '\0')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags,
					width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - stores characters
 * @buffer: the collection of characters
 * @buff_ind: element of array depending on char length
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
