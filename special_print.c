#include "main.h"

/**
 * print_from_to - prints from start to end
 * @start: start
 * @end: end
 * @except: except char
 * Return: number of chars printed
 */
int print_from_to(char *start, char *end, char *except)
{
	int printed_chars = 0;

	while (start <= end)
	{
		if (start != except)
		{
			printed_chars += _putchar(*start);
		}
		start++;
	}

	return (printed_chars);
}

/**
 * print_reverse - print the reverse of the string
 * @args: list of argument
 * @params: parameters
 *
 * Return: number of chars printed
 */
int print_reverse(va_list args, params_t *params)
{
	int printed_chars = 0, len = 0;
	char *str = va_arg(args, char *);

	UNUSED(params);

	if (!str)
		return (0);

	while (*str)
	{
		len++;
		str++;
	}
	str--;

	for (; len > 0; len--, str--)
		printed_chars += _putchar(*str);

	return (printed_chars);
}

/**
 * print_rot13 - prints rot13 string
 * @args: list of arguments
 * @params: parameters
 * Return: number of chars printed
 */
int print_rot13(va_list args, params_t *params)
{
	int i = 0;
	int printed_chars = 0;
	char *str = va_arg(args, char *);

	UNUSED(params);

	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'M')
				|| (str[i] >= 'a' && str[i] <= 'm'))
		{
			printed_chars += _putchar(str[i] + 13);
		}
		else if ((str[i] >= 'N' && str[i] <= 'Z')
				|| (str[i] >= 'n' && str[i] <= 'z'))
		{
			printed_chars += _putchar(str[i] - 13);
		}
		else
		{
			printed_chars += _putchar(str[i]);
		}
		i++;
	}

	return (printed_chars);
}
