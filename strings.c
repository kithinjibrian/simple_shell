#include "main.h"

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

string _strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}

		if (*str1 == '\0')
		{
			return 0;
		}

		str1++;
		str2++;
		n--;
	}

	return 0;
}

string _strstr(const char *haystack, const char *needle)
{
	size_t haystack_len;
	size_t needle_len;
	size_t i;

	if (haystack == NULL || needle == NULL)
	{
		return NULL;
	}

	haystack_len = _strlen(haystack);
	needle_len = _strlen(needle);

	if (needle_len == 0)
	{
		return (char *)haystack;
	}
	for (i = 0; i <= haystack_len - needle_len; i++)
	{
		if (_strncmp(haystack + i, needle, needle_len) == 0)
		{
			return (char *)(haystack + i);
		}
	}

	return NULL;
}