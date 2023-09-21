#include "main.h"

void (*builtins(string cmd))(string *)
{
	int i = 0;
	BuiltinCmds builtincmds[] = {
		{"exit", ss_exit},
		{"env", ss_env},
		{"clear", ss_clear},
		{"setenv", ss_setenv},
		{NULL, NULL}};

	while (builtincmds[i].cmd)
	{
		if (_strcmp(builtincmds[i].cmd, cmd) == 0)
		{
			break;
		}
		i++;
	}

	return (builtincmds[i].fn);
}