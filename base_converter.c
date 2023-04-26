#include "main.h"

/**
 * convert_num_to_string - converts a number to a string
 * @num: number to convert
 * @base: base to convert to
 * @flags: flags
 * @params: parameters
 *
 * Return: converted number
 */
char *convert_num_to_string(long int num, int base,
		int flags, params_t *params)
{
	static char buffer[50];
	char sign = 0;
	char *numbered_string = &buffer[49];
	unsigned long n = num;
	static char *array;

	UNUSED(params);

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	if (flags & CONVERT_LOWERCASE)
		array = "0123456789abcdef";
	else
		array = "0123456789ABCDEF";

	*numbered_string = '\0';

	while (n != 0)
	{
		*--numbered_string = array[n % base];
		n /= base;
	}

	if (sign)
		*--numbered_string = sign;

	return (numbered_string);
}
