#include "main.h"

int main(int argc, string argv[])
{
	if (argc > 1)
	{
		printf("Command: %s\n", argv[1]);
		return (0);
	}

	if (!isatty(STDIN_FILENO))
	{
		char buffer[1024];
		ssize_t bytesRead;

		while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
		{
			buffer[bytesRead] = '\0';
			nonterminal(buffer, argv);
		}
		return 0;
	}

	loop(argc, argv);
	return (0);
}