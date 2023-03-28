#include "main.h"

int main(void)
{
	int len = _printf("%sfive", "five\n", '\n');
	//int len = printf("%s", "");
	int len1 = _printf("%c", 'a');
	int len2 = printf("%sfive", "five\n", '\n');
	printf("len1 = %d\n len2 = %d", len, len2);
	return (0);
}
