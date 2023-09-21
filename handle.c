#include "main.h"

void handles(string *args, string argv[])
{
	int i;
	(void)argv;
	for (i = 0; args[i] != NULL; i++)
	{
		printf("Token: %s\n", args[i]);
	}
}

void handle(string *args, string argv[])
{
	int i, y, result;
	for (i = 0; args[i] != NULL; i++)
	{
		string *snn = split(args[i], "&&||");
		for (y = 0; snn[y] != NULL; y++)
		{
			int nn = 0;
			string *s = split(snn[y], " ");
			while (s[nn] != NULL)
			{
				nn++;
			}
			shift(&history, snn[y]);
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