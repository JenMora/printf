#include "main.h"
/*PRINT CHAR */
/**
*print_char - Prints a character
*@size: the size specifier
*@buffer: the buffer array to handling print
*@types: the list a of arguments
*@width: Width
*@flags: portraying active flags
*@precision: Precision specification
*Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*PRINT A STRING */
/**
*print_string - Prints a string
*@precision: Precision specification
*@width: get width.
*@types: List a of arguments
*@flags:  Calculates active flags
* @buffer: Buffer array to handle print
*@size: Size specifier
*Return: Number of chars printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, j;
char *s = va_arg(types, char *);
UNUSED(width);
UNUSED(buffer);
UNUSED(precision);
UNUSED(flags);
UNUSED(size);
if (s == NULL)
{
s = "(null)";
if (precision >= 6)
s = "      ";
}
while (s[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (j = width - length; j > 0; j--)
write(1, " ", 1);
return (width);
}
else
{
for (j = width - length; j > 0; i--)
write(1, " ", 1);
write(1, &s[0], length);
return (width);
}
}
return (write(1, s, length));
}
/*PRINT PERCENT SIGN */
/**
*print_percent - Prints a percent sign
*@flags:  Calculates active flag
*@width: get width.
*@precision: Precision specification
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@size: Size specifier
*Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(buffer);
UNUSED(flags);
UNUSED(types);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/* PRINT INT*/
/**
*print_int - Print int
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = SIZE_B - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[j--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[j--] = (num % 10) + '0';
num /= 10;
}
j++;
return (write_number(is_negative, j, buffer, flags, width, precision, size));
}
/* PRINT BINARY */
/**
*print_binary - Prints an unsigned number
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width.
*@precision: Precision specification
*@size: Size specifier
*Return: Numbers of char printed.
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int b, m, j, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
b = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = b / m;
for (j = 1; j < 32; j++)
{
m /= 2;
a[j] = (b / m) % 2;
}
for (j = 0, sum = 0, count = 0; j < 32; j++)
{
sum += a[j];
if (sum || j == 31)
{
char z = '0' + a[j];
write(1, &z, 1);
count++;
}
}
return (count);
}
