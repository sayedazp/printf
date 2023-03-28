/**
 * main - entry point func
 * Return - always zero
 */
#include "main.h"
/**
 * cprint - a func
 * @x: an input char
 */
void cprint(char x)
{
	write(1, &x, 1);
}
/**
 * p_char - a func
 * @list: an input
 */
void p_char(va_list list, int *num)
{
	char x = va_arg(list, int);

	cprint(x);
	(*num)++;
}
/**
 * p_string - print string
 * @list: arg
 * Return: void
 */

void p_string(va_list list, int *num)
{
	char *str;
	int i = 0;

	str = va_arg(list, char*);
	while (str[i] != '\0')
	{
		cprint(str[i]);
		i++;
	}
	*num += i;
}
/**
 * p_integer - print integer
 * @list:arg
 * Return: void
 */

/**
 * _printf - print everything
 * @format:arg
 * Return: void
 */
/**
 * handle_print - a func to handle print
 * @i: counter
 * @specify: an arg
 * @num: a num
 * @format: a char pointer
 * @valist: a list
*/
void handle_print(int *i, int *specify, int *num,
char const *format, va_list valist)
{
	unsigned int j = 0;
	t_print t[] = {
		{"c", p_char},
		{"s", p_string},
		{NULL, NULL}
	};

	if (format[*i] == '%')
	{
		*specify = 1;
		(*i)++;
	}
	else
	{
		write(1, &format[*i], 1);
		(*num)++;
	}
	while (t[j].x != NULL && *specify)
	{
		if (*(t[j].x) == format[*i])
		{
			t[j].T_func(valist, num);
			break;
		}
		j++;
	}
	if (*specify == 1)
		*specify = 0;

}
int _printf(const char * const format, ...)
{
	int num = 0;
	int specify = 0;
	unsigned int i = 0, j = 0;
	va_list valist;

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format && format[i])
	{
		handle_print(&i, &specify, &num, format, valist);
		i++;
	}
	va_end(valist);
	return (num);
}
