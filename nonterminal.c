#include "main.h"

void nonterminal(string line, string argv[])
{
	int num_commands;
	string *args;
	(void)argv;

	args = split(&num_commands, line, ";\n");
	handle(num_commands, args, argv);
	free(args);
}