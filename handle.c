#include "main.h"

void handle(int num_commands, string *args, string argv[])
{
	int i, y, result;
	for (i = 0; i < num_commands; i++)
	{
		int nn;
		string *snn = split(&nn, args[i], "&&||");
		for (y = 0; y < nn; y++)
		{
			int a;
			string *s = split(&a, snn[y], " ");
			result = execute(s, argv);
			if (y < nn - 1)
			{
				if (_strstr(args[i], "&&") != NULL)
				{
					if (result != true)
					{
						break;
					}
				}
				else if (_strstr(args[i], "||") != NULL)
				{
					if (result)
					{
						break;
					}
				}
			}
		}
		free(snn);
	}
}