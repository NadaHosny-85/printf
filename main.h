#ifndef MAIN_H
#define MAIN_H
/**
 * struct print_types - this is a structure
 * containing print functions types
 *
 * @spec: function specifier
 * @print_func: a pointer to the function which will be printed
 */
struct func_types
{
	char spec;
	int (*print_func)(va_list);
};

typdef struct func_types print_types;
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_print_type(char c))(va_list);
int print_c(va_list in_arg);
int print_str(va_list in_args);

#endif
