#include "variadic_functions.h"

/**
 * print_all - Prints all of the arguments when specified
 * @format: specifies the necessary operations
 * Return: void
 */

void print_all(const char * const format, ...)
{
va_list args;
va_start(args, format);

char *str;
int i = 0;
float f = 0.0;
char c = '\0';
void *ptr;

while (*format != '\0')
{
switch (*format)
{
case 'c':
c = va_arg(args, int);
printf("%c", c);
break;
case 'i':
i = va_arg(args, int);
printf("%d", i);
break;
case 'f':
f = va_arg(args, double);
printf("%f", f);
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
{
printf("(nil)");
}
else
{
printf("%s", str);
}
break;
default:
break;
}
format++;
if (*format != '\0' && (*format == 'c' || *format == 'i' || *format == 'f' || *format == 's'))
{
printf(", ");
}
}

va_end(args);
printf("\n");
}

