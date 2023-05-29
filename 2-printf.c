#include "main.h"
/* for printing unsigned integers */
/**
 * un_num - prints unsigned numbers
 * @n: list of arguments
 * @pbuff: hosts arrays
 * @flags: checks flags
 * @width: checks width
 * @precision: checks precision
 * @size: checks size
 * Return: Printed characters
 *
 * Authors: Magdalinr N and Jeniffer Moraa
 */
int un_num(va_list n, char pbuff[],
		int flags, int width, int precision, int size)
{
	int i;

	i = SIZE_B - 2;

	unsigned long int num = va_arg(n, unsigned long int);

	num  = new_unSize(num, size);

	if (num == 0)
		pbuff[i--] = '0';

	pbuff[SIZE_B - 1] = '\0';

	while (num > 0)
	{
		pbuff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_un(0, i, pbuff, flags, width, precision, size));
}
/* octaal unsigned numbers printed */
/**
 * prtOCTAL - prints octal
 * @n: number of arguments
 * @pbuff: carries arrays
 * @flags: checks for flags
 * @width: checks width
 * @precision: checks precision
 * @size: checks size
 * Return: Printed characters
 *
 * Author: Magdaline N and Jeniffer Moraa
 */
int prtOCTAL(va_list n, char pbuff[],
		int flags, int width, int precision, int size)
{
	int i;

	i = SIZE_B - 2;

	unsigned long int num = va_arg(n, unsigned long int);
	unsigned long int num1 = num;

	UNUSED(width);

	num = new_unSize(num, size);

	if (num == 0)
		pbuff[i--] = '0';
	pbuff[SIZE_B - 1] = '\0';

	while (num > 0)
	{
		pbuff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && num1 != 0)
		pbuff[i--] = '0';
	i++;
	return (write_un(0, i, pbuff, flags, width, precision, size));
}
/* print haxadecimal number lower case a-f */
/**
 * hexa_lower - prints lower hexa decila values
 * @n: arrays of numbers
 * @pbuff: holds hexa values
 * @flags: chacks flags
 * @width: chacks width
 * @precision: checks precision
 * @size: checks size
 * Return: Printed values in lower hexa
 *
 * Authror - Magdaline N
 */
int hexa_lower(va_list n, char pbuff[], int flags,
		int width, int precision, int size)
{
	return (_hexa(n, "0123456789abcdef", pbuff, flags, 'x',
				width, precision, size));
}
/* print HEXADECIMAL in UPPER */
/**
 * hexa_upper - prints hexa in UPPER
 * @n: the array of numbers
 * @pbuff: holds the values
 * @flags: checks for flags
 * @width: checks for width
 * @precision: checks for precision
 * @size: checks for size
 * Return: values printed
 */
int hexa_upper(va_list n, char pbuff[], int flags, int width,
		int precision, int size)
{
	return (_hexa(n, "0123456789ABCDEF", pbuff,
				flags, 'X', width, precision, size));
}

/* prints hexa in both lower and UPPER */
/**
 * print_hexa - prints both upper and lower hexa values
 * @n: array
 * @map_to: where to place number
 * @pbuff: to hold values
 * @flags: checks for flags
 * @flags1: checks again for flags
 * @width: checks the width
 * @precision: checks the precision
 * @size: checks the size
 * @size: checks the size
 * Return: printed values
 */
int print_hexa(va_list n, char map_to[], char pbuff[],
		int flags, char flags1,
		int width, int precision, int size)
{
	int i = SIZE_B - 2;
	unsigned long int num = va_arg(n, unsigned long int);
	unsigned long int num1 = num;

	UNUSED(width);

	num = new_unsize(num, size);

	if (num == 0)
		buffer[i--] = '0';

	pbuff[SIZE_B - 1] = '\0';

	while (num > 0)
	{
		pbuff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && num1 != 0)
	{
		pbuff[i--] = flags1;
		pbuff[i--] = '0';
	}
	i++;

	return (write_un(0, i, pbuff, flags, width, precision, size));
}
