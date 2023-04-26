#include "main.h"

/**
 * get_flag - get flags from format string
 * @format: string to be checked
 * @params: pointer to parameters
 * Return: flag
 */
int get_flag(char *format, params_t *params)
{
	int flag = 0;

	switch (*format)
	{
		case '-':
			flag = params->minus_flag = 1;
			break;
		case '+':
			flag = params->plus_flag = 1;
			break;
		case ' ':
			flag = params->space_flag = 1;
			break;
		case '0':
			flag = params->zero_flag = 1;
			break;
		case '#':
			flag = params->hashtag_flag = 1;
			break;
	}

	return (flag);
}
