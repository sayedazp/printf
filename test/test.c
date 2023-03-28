//#include "variadic_functions.h"
#include<stdio.h>
#include <unistd.h>
/**
 * p_char - print char
 * @list:arg
 * Return: void
 */
typedef struct print
{
	char *x;
	void (*T_func)(va_list);
} t_print;

int p_char(va_list list)
{
	return (write(1, &c, 1));
}
/**
 * p_string - print string
 * @list:arg
 * Return: void
 */

void p_string(va_list list)
{
	char *str;

	str = va_arg(list, char*);
	if (str == NULL)
		str = "(nil)";
printf("%s", str);
}
/**
 * p_integer - print integer
 * @list:arg
 * Return: void
 */

void p_integer(va_list list)
{
	printf("%i", va_arg(list, int));
}
/**
 * p_float - print float
 * @list:arg
 * Return: void
 */

void p_float(va_list list)
{
	printf("%f", va_arg(list, double));
}
/**
 * print_all - print everything
 * @format:arg
 * Return: void
 */
void print_all(const char * const format, ...)

{
	unsigned int i, j;
	t_print t[] = {
		{"c", p_char},
		{"s", p_string},
		{"i", p_integer},
		{"f", p_float},
		{NULL, NULL}
	};
	va_list valist;
	char *s = "";

	va_start(valist, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (t[j].x != NULL)
		{
			if (*(t[j].x) == format[i])
			{
				t[j].T_func(valist);
				break;
			}
			j++;
		}
		i++;
	}
	va_end(valist);
}
int main(void)
{
    print_all("sayed");
}