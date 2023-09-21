#include "main.h"

int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

void print(int fd, string str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(fd, str[i]);
	}
}