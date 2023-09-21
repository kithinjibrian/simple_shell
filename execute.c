#include "main.h"

int execute(string *args, string argv[])
{
	Builtin builtin;
	builtin = builtins(args[0]);
	if (builtin != NULL)
	{
		builtin(args);
		return (true);
	}
	return (run(args, argv));
}