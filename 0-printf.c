#include "main.h"
/**
 * _printf - a function that produces output according to format
 * @pbuff: the collection of characters
 * @buffn: element of array depending on char length
 * Return: the printed characters from string
 *
 * Author: MAgdaline N.
 */

void buff_prt(char pbuff[], int *buffn);
int _printf(const char *format, ...)
{
	int i, prt = 0, prtdc = 0, flags, width, precision;
	int size, buffn = 0;
	char pbuff[SIZE_B];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '\0')
		{
			pbuff[buffn++] = format[i];
			if (buffn == SIZE_B)
				buff_prt(pbuff, &buffn);
			ptrdc++;
		}
		else
		{
			buff_prt(pbuff, &buffn);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			prt = handle_print(format, &i, list, pbuff, flags,
					width, precision, size);
			if (prt == -1)
				return (-1);
			prtdc += prt;
		}
	}
	buff_prt(pbuff, &buffn);

	va_end(list);

	return (prtdc);
}

/**
 * buff_prt - stores characters
 * @pbuff: the collection of characters
 * @buffn: element of array depending on char length
 *
 * Author: MAgdaline N.
 */

void buff_prt(char pbuff[], int *buffn)
{
	if (*buffn > 0)
		write(i, &pbuff[0], *buffn);
	*buffn = 0;
}
