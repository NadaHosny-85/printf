#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * print_c - function prints char
 *
 * @in_arg: argument input
 *
 * Return: 1 which is count of printed
 * chars
 */
int print_c(va_list in_arg)
{
	_putchar(va_arg(in_arg, int));
	return (1);
}
