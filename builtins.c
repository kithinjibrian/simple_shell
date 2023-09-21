#include "main.h"

void (*builtins(string cmd))(string *)
{
	int i = 0;
	BuiltinCmds builtincmds[] = {
		{"exit", ss_exit},
		{NULL, NULL}};

	while (builtincmds[i].cmd)
	{
		if (strcmp(builtincmds[i].cmd, cmd) == 0)
		{
			break;
		}
		i++;
	}

	return (builtincmds[i].fn);
}