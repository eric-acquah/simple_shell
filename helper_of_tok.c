#include "main.h"

/**
 *skip_delim - skip delimeters accountered in string
 *@str: pointer to string
 *@delim: delimeter string
 *Return: pointer to delimeterless string
 */

char *skip_delim(char *str, char *delim)
{
	int i, j;

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
			if (str[i] == delim[j])
				break;
		if (delim[j] == '\0')
			return (str + i);
	}
	return (str + i);
}

/**
 *get_token - function to extract each token from string
 *@s: pointer to string
 *@i: length of string
 *Return: pointer to token
 */

char *get_token(char *s, int i)
{
	int j;
	char *tmp;

	tmp = malloc(sizeof(char) * (i + 1));
	for (j = 0; j < i; j++)
		tmp[j] = s[j];
	tmp[j] = '\0';
	return (tmp);
}

/**
 *num_words - return the number of words within a string
 *@s: string pointer
 *@delim: delimeter string
 *Return: number of words
 */

int num_words(char *s, char *delim)
{
	char *tmp;
	int i, j, num_tok = 0;

	tmp = s;
	for (i = 0; tmp[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (tmp[i] == delim[j])
			{
				tmp += i;
				tmp = skip_delim(tmp, delim);
				if (*tmp)
					num_tok++;
				i = -1;
				break;
			}
		}
	}
	return (num_tok);
}
