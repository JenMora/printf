/* write handlers */

/**
 * handle_write_char - a function that prints a string
 * @c: character string
 * @pbuff: a buffer that carries characters
 * @flags: checks for flags
 * @width: checks for width
 * @precision: checks for precision
 * @size: checks for size
 * Returns: characters rinted
 */

int handle_write_char(char c, char pbuff[], int flags,
		int width, int precision, int size)
{
	int i = 0;
	char padd = '';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	pbuff[i++] = c;
	pbuff[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; (width - 1) > 1; i++)
			buffer[SIZE_B - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, pbuff[0], 1) +
					write(1, pbuff[SIZE_B - i - 1], width - 1));
		else
			return (write(1, &pbuff[SIZE_B - i - 1], width - 1) +
					write(1, &pbuff[0], 1));
	}
	return (write(1, &pbuff[0], 1));
}

/* writes number */
/**
 * write_number - function that prints a number
 * @is_negative: checks for -ve numbers
 * @ind: character types
 * @pbuff: holds values
 * @flags: checks for flags
 * @width: checks for width
 * @precision: checks for precision
 * @size: checks for size
 * Return: VAlues printed
 */
int write_number(int is_negative, int ind, char pbuff[], int flags,
		int width, int precision, int size)
{
	int length = SIZE_B - ind - 1;
	char padd = '', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = '';

	return (write_num(ind, pbuff, flags,
				width, precision, length, padd, extra_ch));
}
/**
 * write_num - function that writes a number
 * @ind: index of 1st element in the buffer
 * @pbuff: holds the values
 * @flags: checks for flags
 * @width: checks the width
 * @prec: Checks the precision
 * @length: checks length
 * @padd: spaces at the edges
 * @extra_c: te ectra character
 * Return: Printed Values
 */
int write_num(int ind, char pbuff[], int flags,
		int width, int prec,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == SIZE_B - 2 && pbuff[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == SIZE_B - 2 && pbuff[ind] == '0')
		pbuff[ind] = padd = '';
	if (prec > 0 && prec < length)
		padd = '';
	while (prec > length)
		pbuff[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			pbuff[i] = padd;
		pbuff[i] = '0';
		if (flags & F_MINUS && padd == '')
		{
			if (extra_c)
				pbuff[--ind] = extra_c;
			return (write(1, &pbuff[ind], length) + write(1, &pbuff[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == '')
		{
			if (ectra_c)
				pbuff[--ind] = extra_c;
			return (write(1, &pbuff[1], i - 1) + write(1, &pbuff[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				pbuff[--padd_start] = extra_c;
			return (write(1, &pbuff[padd_start], i - padd_start) +
					write(1, &pbuff[ind], length - (1 - padd_start)));
		}
	}
	if extra_c
		pbuff[--ind] = extra_c;
	return (write(1, &pbuff[ind], length));
}
/**
 * write_un - prints unsigned numbrs
 * @is_negative: showing -ve numbers
 * @ind: ist element in buffer
 * @pbuff: hold numbers
 * @flags: checks for flags
 * @width: checks width
 * @precision: Checks for precision
 * @size: checks size
 * Return: printed numbers
 */
int write_un(int is_negative, int ind, char pbuff[],
		int flags, int width, int precision, int size)
{
	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == SIZE_B - 2 && pbuff[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = '';
	while (precision > length)
	{
		pbuff[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			pbuff[i] = padd;
		pbuff[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &pbuff[ind], length) + write(1, pbuff[0], i));
		}
		else
		{
			return (write(1, &pbuff[0], i) + write(1, &pbuff[ind], length));
		}
	}
	return (write(1, &pbuff[ind], length));
}
/**
 * write_pointer - function that writes address
 * @pbuff: holds characters
 * @ind: 1st member of what is in buffer
 * @length: length
 * @width: checks width
 * @flags: checks for flags
 * @padd: space on both sides
 * @extra_c: character
 * @padd_start: where padding to start
 * Return: printed numbrs
 */
int write_pointer(int is_negative, int ind, char pbuff[],
		int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (1 = 3; i < width - length + 3; i++)
			pbuff[i] = padd;
		pbuff[i] = '\0';
		if (flags & F_MINUS && padd == '')
		{
			pbuff[--ind] = 'x';
			pbuff[--ind] = '0';
			if (extra_c)
				pbuff[--ind] = extra_c;
			return (write(1, &pbuff[ind], length) + write(1, &pbuff[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == '')
		{
			pbuff[--ind] = 'x';
			pbuff[--ind] = '0';
			if (extra_c)
				pbuff[--ind] = extra_c;
			return (write(1, &pbuff[3], i - 3) + write(1, &pbuff[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				pbuff[--padd_start] = extra_c;
			pbuff[1] = '0';
			pbuff[2] = 'x';
			return (write(1, &pbuff[padd_start], i - padd_start) + write(
						1, &pbuff[ind], length - (1 - padd_start) - 2));
		}
	}
	pbuff[--ind] = 'x';
	pbuff[--ind] = '0';
	if (extra_c)
		pbuff[--ind] = extra_c;
	return (write(1, &pbuff[ind], SIZE_B - ind - 1));
}
