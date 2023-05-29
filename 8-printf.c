#include "main.h"

/* handle print */
/**
 * handle_print - a funtion that prints an arg as per type
 * @fmt: the formated string
 * @list: the list
 * @ind: ind
 * @pbuff: hold the characters
 * @flags: chekcs for flags
 * @width: checks for width
 * @precision: checks for precision
 * @size: checks for size
 * Return: 1 or 2
 */

int handle_print(const char *fmt, int *ind, va_list list, char pbuff[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, prtdc = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_ind}, {'d', print_int},
		{'b', print_binary}, {'u', un_num}, {'o', prtOCTAL},
		{'x', hexa_lower}, {'x', hexa_upper}, {'p', print_pointer},
		{'S', print_non_printable}, {'r', print_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, pbuff, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == '')
			unknow_len += write(1, "", 1);

		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != '' &&fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == '')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (prtdc);
}
