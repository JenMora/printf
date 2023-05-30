#include "main.h"
/* Authors - Jeniffer Moraa & Magdaline Njuguna */
/**
*get_width - Calculates the width for printing
*@format: Formatted string in which to print the arguments
*@i: List of arguments to be printed
*@list: variadic declaration
*Return: width.
*/
int get_width(const char *format, int *i, va_list list)
{
int a;
int width = 0;

for (a = *i + 1; format[a] != '\0'; a++)
{
if (is_digit(format[a]))
{
width *= 10;
width += format[a] - '0';
}
else if (format[a] == '*')
{
a++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = a - 1;
return (width);
}
