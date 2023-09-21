#include "main.h"

void ss_exit(string *args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

void ss_env(string *args)
{
	int i;
	(void)args;
	for (i = 0; environ[i] != NULL; i++)
	{
		print(1, environ[i]);
		print(1, "\n");
	}
}

void ss_clear(string *args)
{
	(void)args;
	system("clear");
}

void ss_setenv(string *args)
{
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("hsh:");
	}
}

void ss_unsetenv(string *args)
{
	if (unsetenv(args[1]) == -1)
	{
		perror("hsh:");
	}
}