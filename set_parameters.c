#include "main.h"
/**
 * init_params - initialize parameters
 * @params: pointer to parameters
 * @args: unused
 * Return: void
 */
void init_params(params_t *params, va_list args)
{
	params->unsign = 0;

	params->minus_flag = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->zero_flag = 0;
	params->hashtag_flag = 0;

	params->width = 0;
	params->percision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;

	UNUSED(args);
}
