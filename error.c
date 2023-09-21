#include "main.h"

string one(string name, string arg)
{
	char count[20];
	string error;
	int len;

	sprintf(count, "%d", history.count);
	len = _strlen(name) + _strlen(arg) + 16;
	error = malloc(sizeof(char) * (len + 1));
	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, count);
	_strcat(error, ": ");
	_strcat(error, arg);
	_strcat(error, ": not found\n");
	return (error);
}