#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct print - multiple choice print
 * @x: char Type of print
 * @T_func: funct
 */
typedef struct print
{
	char *x;
	void (*T_func)(va_list, int *num);
} t_print;

void handle_print(unsigned int *i, int *specify, int *num,
char const *format, va_list valist);
void cprint(char x);
void p_char(va_list list, int *num);
void p_string(va_list list, int *num);
int _printf(const char * const format, ...);

#endif

