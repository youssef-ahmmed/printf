#include "main.h"

/**
 * print_pointer - prints a the address of the variable
 * @args: arguments
 * @params: parameters
 * Return: bytes printed
 */
int print_pointer(va_list args, params_t *params)
{
	unsigned long int number = va_arg(args, unsigned long int);
	char *address;

	if (!number)
		return (_puts("(nil)"));

	address = convert_num_to_string(number, 16,
			CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--address = 'x';
	*--address = '0';

	return (print_number(address, params));
}

/**
 * print_unsigned - prints an unsigned number
 * @args: arguments
 * @params: parameters
 * Return: bytes printed
 */
int print_unsigned(va_list args, params_t *params)
{
	unsigned long long_number;

	if (params->l_modifier)
		long_number = (unsigned long) va_arg(args, unsigned long);
	else if (params->h_modifier)
		long_number = (unsigned short int) va_arg(args, unsigned int);
	else
		long_number = (unsigned int) va_arg(args, unsigned int);

	params->unsign = 1;

	return (print_number(convert_num_to_string(long_number, 10,
					CONVERT_UNSIGNED, params), params));
}
