#include "main.h"

int _printf(const char *format, ...) 

	int num_chars_printed = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
	if (*format == '%')
       	{
	format++;
       
	if (*format == '%')
       	{
	putchar('%');
	num_chars_printed++;
	}
       	else if (*format == 'c')
       	{
	
	char c = va_arg(args, int);
	putchar(c);
	num_chars_printed++;
	}
        else if (*format == 's')
       	{
	
	char *s = va_arg(args, char *);
	while (*s != '\0')
       	{
	putchar(*s);
	s++;
	num_chars_printed++;
	}
	}
	}
       	else
       	{
	putchar(*format);
	num_chars_printed++;
	}
	format++;
	}
	va_end(args);
        return num_chars_printed;
}
