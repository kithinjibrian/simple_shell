#include "main.h"

void nonterminal(string line, string argv[])
{
	string *args;
	(void)argv;

	args = split(line, "\n");
	handle(args, argv);
	free(args);
}