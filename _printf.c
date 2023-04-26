#include "main.h"

/**
 * _printf - prints a string
 * @format: string to be printed
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	char *curr, *start_specifier;
	va_list args;
	params_t params = DEFAULT_PARAMETERS;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (curr = (char *) format; *curr; curr++)
	{
		init_params(&params, args);
		if (*curr != '%')
		{
			printed_chars += _putchar(*curr);
			continue;
		}
		start_specifier = curr;
		curr++;
		while (get_flag(curr, &params))
			curr++;
		curr = get_width(curr, &params, args);
		curr = get_precision(curr, &params, args);
		if (get_length(curr, &params))
			curr++;
		if (!get_specifier(curr))
			printed_chars += print_from_to(start_specifier, curr,
					params.l_modifier || params.h_modifier ? curr - 1 : 0);
		else
			printed_chars += get_printed_function(curr, args, &params);

	}
	_putchar(BUFFER_RESET);
	va_end(args);
	return (printed_chars);
}
