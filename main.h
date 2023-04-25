#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)
#define NULL_STRING "(null)"

#define MAX_OUT_BUFFER 1024
#define BUFFER_RESET -1

#define DEFAULT_PARAMETERS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct token
 * @unsign: flag
 * 
 * @minus_flag: flag
 * @plus_flag: flag
 * @space_flag: flag
 * @zero_flag: flag
 * @hashtag_flag: flag
 * 
 * @width: width
 * @percision: precision
 * 
 * @h_modifier: flag
 * @l_modifier: flag
*/
typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int minus_flag : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int hashtag_flag : 1;

	unsigned int width;
	unsigned int percision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: the associated function
*/
typedef struct specifier
{
	char *specifier;
	int (*function) (va_list, params_t *params);
} specifier_t;

/* standard_output module */
int _puts(char *str);
int _putchar(int c);

/* printf module */
int _printf(const char *format, ...);
void init_params(params_t *params, va_list args);

/* print_functions module */
int print_char(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_S(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);

/* other_print_functions module */
int print_pointer(va_list args, params_t *params);
int print_unsigned(va_list args, params_t *params);

/* number_system_converter module */
int print_binary(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);

/* base_converter module */
char *convert_num_to_string(long int num, int base, int flags, params_t *params);

/* getters functions */
int get_flag(char *format, params_t *params);
int get_length(char *format, params_t *params);
char *get_width(char *format, params_t *params, va_list args);
char *get_precision(char *format, params_t *params, va_list args);

/* get_specifier module */
int (*get_specifier(char *format))(va_list args, params_t *params);
int get_printed_function(char *format, va_list args, params_t *params);

/* special_print module */
int print_from_to(char *start, char *end, char *except);
int print_reverse(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);

/* helper_functions module */
int is_digit(char c);
int _strlen(char *str);
int print_number(char *num_str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

#endif
