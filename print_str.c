#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * print_str - function prints a string
 * using write
 *
 * @in_args: input arguments
 *
 * Return: count of printed strings
 */
int print_str(va_list in_args)
{
	char c;

	char *str;

	int str_cnt = 0;

	str = va_arg(in_args, char*);
	if (str == NULL)
	{
		str = "(null)";
	}
	else
	{
		while (str[str_cnt] != '\0')
		{
			c = str[str_cnt];
			write(1, &c, 1);
			str_cnt++;
		}
	}
	return (str_cnt);
}
