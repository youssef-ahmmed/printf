#include "main.h"

/**
 * get_specifier - finds the format function
 * @format: string to be checked
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *format))(va_list args, params_t *params)
{
	specifier_t specifier[] = {
		{ "c", print_char },
		{ "d", print_int },
		{ "i", print_int },
		{ "s", print_string },
		{ "%", print_percent },
		{ "b", print_binary },
		{ "o", print_octal },
		{ "u", print_unsigned },
		{ "x", print_hex },
		{ "X", print_HEX },
		{ "p", print_pointer },
		{ "S", print_S },
		{ "r", print_reverse },
		{ "R", print_rot13 },
		{ NULL, NULL }
	};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*format == specifier[i].specifier[0])
		{
			return (specifier[i].function);
		}
		i++;
	}

	return (NULL);
}

/**
 * get_printed_function - finds the format function
 * @format: string to be checked
 * @args: list of arguments
 * @params: pointer to parameters
 *
 * Return: the number of bytes printed
 */
int get_printed_function(char *format, va_list args, params_t *params)
{
	int (*function)(va_list, params_t*) = get_specifier(format);

	if (function)
		return (function(args, params));
	return (0);
}
