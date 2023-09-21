#include "main.h"

bool isDelimiter(char c, const char *delimeters)
{
	while (*delimeters)
	{
		if (c == *delimeters)
			return true;
		delimeters++;
	}
	return false;
}

char **str_tok(const char *input, const char *delimiters, int *tokenCount)
{
	int tokenCapacity = 10;
	char **tokens = (char **)malloc(tokenCapacity * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	bool inToken = false;
	char token[100];
	int tokenIndex = 0;
	*tokenCount = 0;

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (isDelimiter(input[i], delimiters))
		{
			if (inToken)
			{
				token[tokenIndex] = '\0';
				tokens[(*tokenCount)++] = strdup(token);
				if (*tokenCount == tokenCapacity)
				{
					tokenCapacity *= 2;
					tokens = (char **)realloc(tokens, tokenCapacity * sizeof(char *));
					if (tokens == NULL)
					{
						perror("Memory allocation error");
						exit(EXIT_FAILURE);
					}
				}
				tokenIndex = 0;
				inToken = false;
			}
		}
		else
		{
			token[tokenIndex++] = input[i];
			inToken = true;
		}
	}
	if (inToken)
	{
		token[tokenIndex] = '\0';
		tokens[(*tokenCount)++] = strdup(token);
	}

	return tokens;
}

string *split(int *num_commands, string line, string delimeter)
{
	return str_tok(line, delimeter, num_commands);
}