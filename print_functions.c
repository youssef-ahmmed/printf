#include "main.h"
/**
 * print_char - prints a char
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_char(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, printed_chars = 0, character = va_arg(args, int);

	if (params->minus_flag)
		printed_chars += _putchar(character);
	while (pad++ < params->width)
		printed_chars += _putchar(pad_char);
	if (!params->minus_flag)
		printed_chars += _putchar(character);

	return (printed_chars);
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char pad_char = ' ';
	unsigned int pad = 0, printed_chars = 0, i = 0, j;
	UNUSED(params);

	if ((int) !str)
		return (_puts(NULL_STRING));

	j = pad = _strlen(str);
	if (params->percision < pad)
		j = pad = params->percision;

	if (params->minus_flag)
	{
		if (params->percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				printed_chars += _putchar(*str++);
		else
			printed_chars += _puts(str);
	}

	while (j++ < params->width)
		printed_chars += _putchar(pad_char);

	if (!params->minus_flag)
	{
		if (params->percision != UINT_MAX)
			for (i = 0; i < pad; i++)
				printed_chars += _putchar(*str++);
		else
			printed_chars += _puts(str);
	}

	return (printed_chars);
}

/**
 * print_number - prints a number
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_int(va_list args, params_t *params)
{
	long number;

	if (params->l_modifier)
		number = va_arg(args, long);
	else if (params->h_modifier)
		number = (short int) va_arg(args, int);
	else
		number = (int) va_arg(args, int);

	return (print_number(convert_num_to_string(number, 10, 0, params), params));
}

/**
 * print_S - prints a string
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int printed_chars = 0;

	if ((int) !str)
		return (_puts(NULL_STRING));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			printed_chars += _putchar('\\');
			printed_chars += _putchar('x');
			hex = convert_num_to_string(*str, 16, 0, params);
			if (!hex[1])
				printed_chars += _putchar('0');
			printed_chars += _puts(hex);
		}
		else
			printed_chars += _putchar(*str);
	}

	return (printed_chars);
}

/**
 * print_percent - prints a percent
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_percent(va_list args, params_t *params)
{
	UNUSED(params);
	UNUSED(args);

	return (_putchar('%'));
}
