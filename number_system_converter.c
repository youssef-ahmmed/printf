#include "main.h"

/**
 * print_binary - prints binary
 * @args: list of arguments
 * @params: parameters
 * Return: number of chars printed
*/
int print_binary(va_list args, params_t *params)
{
    unsigned int binary_num = va_arg(args, unsigned int);
    char *str = convert_num_to_string(binary_num, 2, CONVERT_UNSIGNED, params);
    int printed_chars = 0;

    if (params->hashtag_flag && binary_num)
        *--str = '0';

    params->unsign = 1;
    return (printed_chars += print_number(str, params));
}

/**
 * print_octal - prints octal
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_octal(va_list args, params_t *params)
{
    unsigned long octal_num;
    int printed_chars = 0;
    char *str;

    if (params->l_modifier)
        octal_num = (unsigned long) va_arg(args, unsigned long);
    else if (params->h_modifier)
        octal_num = (unsigned short int) va_arg(args, unsigned int);
    else
        octal_num = (unsigned int) va_arg(args, unsigned int);

    str = convert_num_to_string(octal_num, 8, CONVERT_UNSIGNED, params);

    if (params->hashtag_flag && octal_num)
        *--str = '0';

    params->unsign = 1;
    return (printed_chars += print_number(str, params));
}

/**
 * print_hex - prints hex small
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_hex(va_list args, params_t *params)
{
    unsigned long long_num;
    int printed_chars = 0;
    char *str;

    if (params->l_modifier)
        long_num = (unsigned long) va_arg(args, unsigned long);
    else if (params->h_modifier)
        long_num = (unsigned short int) va_arg(args, unsigned int);
    else
        long_num = (unsigned int) va_arg(args, unsigned int);

    str = convert_num_to_string(long_num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
    if (params->hashtag_flag && long_num)
    {
        *--str = 'x';
        *--str = '0';
    }

    params->unsign = 1;
    return (printed_chars += print_number(str, params));
}

/**
 * print_HEX - prints hex big
 * @args: list of arguments
 * @params: parameters
 * 
 * Return: number of chars printed
*/
int print_HEX(va_list args, params_t *params)
{
    unsigned long long_num;
    int printed_chars = 0;
    char *str;

    if (params->l_modifier)
        long_num = (unsigned long) va_arg(args, unsigned long);
    else if (params->h_modifier)
        long_num = (unsigned short int) va_arg(args, unsigned int);
    else
        long_num = (unsigned int) va_arg(args, unsigned int);

    str = convert_num_to_string(long_num, 16, CONVERT_UNSIGNED, params);
    if (params->hashtag_flag && long_num)
    {
        *--str = 'x';
        *--str = '0';
    }

    params->unsign = 1;
    return (printed_chars += print_number(str, params));
}