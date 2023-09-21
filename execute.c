#include "main.h"

int execute(string *args)
{
	Builtin builtin;
	builtin = builtins(args[0]);
	if (builtin != NULL)
	{
		builtin(args);
		return (true);
	}
	return (run(args));
}