#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void print(string str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}