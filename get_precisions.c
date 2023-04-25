#include "main.h"

/**
 * get_precision - get precision of format string
 * @format: string to be checked
 * @params: pointer to parameters
 * @args: list of arguments
 *
 * Return: pointer to next format
 */
char *get_precision(char *format, params_t *params, va_list args)
{
	int precision = 0;

	if (*format != '.')
		return (format);

	format++;
	if (*format == '*')
	{
		precision = va_arg(args, int);
		format++;
	}
	else
	{
		while (is_digit(*format))
		{
			precision = precision * 10 + (*format++ - '0');
		}
	}

	params->percision = precision;
	return (format);
}
