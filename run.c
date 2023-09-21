#include "main.h"

int run(string *args)
{
	pid_t pid;
	int status;
	string command = location(args[0]);

	pid = fork();

	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("SeaShell");
			return (false);
		}
	}
	else if (pid < 0)
	{
		perror("SeaShell");
		return (false);
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (true);
}