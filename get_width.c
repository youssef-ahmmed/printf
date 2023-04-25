#include "main.h"

/**
 * get_width - get width of format string
 * @format: string to be checked
 * @params: pointer to parameters
 *@args: arguments
 *
 * Return: pointer to next format
 */
char *get_width(char *format, params_t *params, va_list args)
{
	int width = 0;

	if (*format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (is_digit(*format))
		{
			width = width * 10 + (*format++ - '0');
		}
	}

	params->width = width;

	return (format);
}
