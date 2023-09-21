#include "main.h"

void loop(int argc, string argv[])
{
	bool status = true;
	int num_commands;
	string line;
	string *args;
	(void)argc;

	do
	{
		prompt();
		line = _getline();
		args = split(&num_commands, line, ";");
		handle(num_commands, args, argv);

		free(line);
		free(args);
	} while (status);
}