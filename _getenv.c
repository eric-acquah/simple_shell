#include "main.h"

/**
 *_getenv - get environment variables
 *@env: environment variables
 *Return: pointer to array of tokenized strings
 */
char *_getenv(char *env[], char *usr_input)
{
	int i, jag;

	jag = _strlen(usr_input);

	i = 0;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], usr_input, jag) == 0)
		{
			return (env[i] + (jag + 1));
		}
		i++;
	}
	return (NULL);
}
