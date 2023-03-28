//#include "variadic_functions.h"
#include<stdio.h>
#include <unistd.h>
#include<stdarg.h>
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

void cprint(char x)
{
	write(1, &x, 1);
}
void p_char(va_list list)
{
	char x = va_arg(list, int);
	cprint(x);
}
/**
 * p_string - print string
 * @list:arg
 * Return: void
 */

void p_string(va_list list)
{
	char *str;
	int i = 0;
	str = va_arg(list, char*);
	/*if (str == NULL)
		str = "(nil)";*/
	
	while (str[i] != '\0')
	{
		cprint(str[i]);
		i++;   
	}
}
/**
 * p_integer - print integer
 * @list:arg
 * Return: void
 */

void p_integer(va_list list)
{
	printf("%i", va_arg(list, char));
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
void _printf(const char * const format, ...)
{
	int specify = 0;
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
		if(format[i] == '%')
		{
			specify = 1;
			i++;
		}else
		{
			write(1,&format[i],1);
		}
		while (t[j].x != NULL && specify)
		{
			if (*(t[j].x) == format[i])
			{
				t[j].T_func(valist);
				break;
			}
			j++;
		}
		if(specify == 1)
		{
			specify = 0;
		}
		i++;
	}
	va_end(valist);
}
int main(void)
{ 
	//print_all("a%s", "ahmed");
	_printf("%s","sss");
	putchar('\n');
}