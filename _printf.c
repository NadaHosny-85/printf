#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/*
 * Description - this program emulates
 * the printf function
 */
/**
 * get_print_type - function searches through
 * a structure for specifier so its
 * print function is called
 *
 * @c: specifier character
 *
 * Return: pointer to the function
 * that prints
 * NULL if nothing is found
 */
int (*get_print_type(char c))(va_list)
{
	int i;

	print_types p_functions[] = {
		{'c', print_c}, {'s', print_str},
		{'\0', NULL}
	};
	for (i = 0; p_functions[i].spec; i++)
	{
		if (c == p_functions[i].spec)
		{
			return (p_functions[i].print_func);
		}
	}
	return (NULL);
}
/**
 * _printf - function acts as the printf
 * print function
 *
 * @format: the input to be printed
 *
 * Return: count of printed chars
 */
int _printf(const char *format, ...)
{
	int (*fmt_type)(va_list);

	int i;

	int fmt_cnt = 0;

	va_list in_args;

	va_start(in_args, format);

	if (format == NULL)
	{return (-1); }
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i] == '\0')
			{
				return (-1);
			}
			else
			{fmt_type = get_print_type(format[i + 1]);
				if (fmt_type != NULL)
				{fmt_cnt += fmt_type(in_args); }
				else
				{return (-1); }
			}
		}
		else
		{_putchar(format[i]);
			fmt_cnt++; }
	}
	va_end(in_args);
	return (fmt_cnt);
}
