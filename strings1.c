#include "main.h"

char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp = src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

char *_strchr(const char *str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

string _strtok(char *str, const char *delim)
{
	static char *nextToken = NULL;
	char *tokenStart;

	if (str == NULL)
	{
		str = nextToken;
	}

	while (*str != '\0' && _strchr(delim, *str) != NULL)
	{
		str++;
	}

	if (*str == '\0')
	{
		nextToken = NULL;
		return NULL;
	}

	tokenStart = str;
	while (*str != '\0' && _strchr(delim, *str) == NULL)
	{
		str++;
	}

	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}

	nextToken = str;
	return tokenStart;
}

char *_strdup(const char *str)
{
	size_t length;
	char *newStr = NULL;

	if (str == NULL)
	{
		return NULL;
	}

	length = _strlen(str);

	newStr = (char *)malloc(length + 1);

	if (newStr == NULL)
	{
		return NULL;
	}

	_strcpy(newStr, str);

	return newStr;
}

string _strncat(char *dest, const char *src, size_t n)
{

	char *dest_end = dest + _strlen(dest);

	while (*src != '\0' && n > 0)
	{
		*dest_end++ = *src++;
		n--;
	}

	*dest_end = '\0';

	return dest;
}
