#include "main.h"

/**
 * get_length - get length of format string
 * @format: string to be checked
 * @params: pointer to parameters
 * Return: length of format
 */
int get_length(char *format, params_t *params)
{
	int length = 0;

	switch (*format)
	{
		case 'l':
			length = params->l_modifier = 1;
			break;
		case 'h':
			length = params->h_modifier = 1;
			break;
	}

	return (length);
}
