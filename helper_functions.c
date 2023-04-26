#include "main.h"

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * print_number - prints an integer
 * @num_str: string representation of the integer
 * @params: parameters
 *
 * Return: number of characters printed
 */
int print_number(char *num_str, params_t *params)
{
	unsigned int i = _strlen(num_str);
	int negative = (!params->unsign && *num_str == '-');

	if (!params->percision && *num_str == '0' && !num_str[1])
		num_str = "";
	if (negative)
	{
		num_str++;
		i--;
	}

	if (params->percision != UINT_MAX)
	{
		while (i++ < params->percision)
		{
			*--num_str = '0';
		}
	}
	if (negative)
		*--num_str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(num_str, params));
	else
		return (print_number_left_shift(num_str, params));
}

/**
 * print_number_right_shift - prints an integer
 * @str: string representation of the integer
 * @params: parameters
 * Return: number of characters printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';

	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;

	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');

	while (i++ < params->width)
		n += _putchar(pad_char);

	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints an integer
 * @str: string representation of the integer
 * @params: parameters
 * Return: number of characters printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
	{
		n += _putchar('+');
		i++;
	}
	else if (params->space_flag && !neg2 && !params->unsign)
	{
		n += _putchar(' ');
		i++;
	}
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);

	return (n);
}
