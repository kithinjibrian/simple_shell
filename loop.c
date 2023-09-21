#include "main.h"

void loop(int argc, string argv[])
{
	bool status = true;
	string line;
	string *args;
	(void)argc;
	(void)argv;

	do
	{
		prompt();
		line = _getline();
		args = split(line, ";");
		handle(args, argv);

		free(line);
		free(args);
	} while (status);
}