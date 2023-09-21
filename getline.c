#include "main.h"

string _getline(void)
{
	int position = 0, buffer_size = BUFFER_SIZE, c;
	char *buffer = malloc(sizeof(char) * buffer_size);

	if (!buffer)
	{
		printf("Allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = c;
		}

		position++;

		if (position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;
			buffer = realloc(buffer, buffer_size);
			if (!buffer)
			{
				printf("Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}