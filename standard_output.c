#include "main.h"

/**
 * _puts - prints a string
 * @str: string
 * Return: number of chars printed
 */
int _puts(char *str)
{
	char *p = str;
	int count = 0;

	while (*p)
	{
		_putchar(*p++);
		count++;
	}

	return (count);
}

/**
 * _putchar - prints a char
 * @c: char to be printed
 * Return: number of chars printed
 */
int _putchar(int c)
{
	static int buff_idx;
	static char buffer[MAX_OUT_BUFFER];

	if (c == BUFFER_RESET || buff_idx >= MAX_OUT_BUFFER)
	{
		write(1, buffer, buff_idx);
		buff_idx = 0;
	}

	if (c != BUFFER_RESET)
	{
		buffer[buff_idx++] = c;
	}

	return (1);
}
