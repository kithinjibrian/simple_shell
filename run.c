#include "main.h"

int run(string *args, string argv[])
{
	pid_t pid;
	int status;
	string command = location(args[0]);

	if (command != NULL)
	{
		pid = fork();

		if (pid == 0)
		{
			if (execve(command, args, environ) == -1)
			{
				printf("SeaShell");
				return (false);
			}
		}
		else if (pid < 0)
		{
			printf("SeaShell");
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
	print(STDERR_FILENO, one(argv[0], args[0]));
	return (false);
}