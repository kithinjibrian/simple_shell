#include "main.h"

void loop(int argc, string argv[])
{
	bool status = true;
	bool result = true;
	int num_commands;
	string line;
	string *args;
	do
	{
		line = _getline();
		args = split(&num_commands, line, ";");

		for (int i = 0; i < num_commands; i++)
		{
			int nn;
			string *snn = split(&nn, args[i], "&&||");
			for (int y = 0; y < nn; y++)
			{
				int a;
				string *s = split(&a, snn[y], " ");
				result = execute(s);
				if (y < nn - 1)
				{
					if (strstr(args[i], "&&") != NULL)
					{
						if (result != true)
						{
							break;
						}
					}
					else if (strstr(args[i], "||") != NULL)
					{
						if (result)
						{
							break;
						}
					}
				}
			}
		}

		free(line);
		free(args);
	} while (status);
}