#include "main.h"

/**
 *_printf - prints to output according to format
 *@format: character string
 *
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	char *buffer;

	va_start(args, format);
	count = vsnprintf(NULL, 0, format, args);
	va_end(args);

	buffer = malloc(count + 1);
	if (buffer == NULL)
       	{
	return -1;
	}

	va_start(args, format);
	count = vsnprintf(buffer, count + 1, format, args);
	va_end(args);

	fwrite(buffer, 1, count, stdout);
	free(buffer);

	return count;
}

