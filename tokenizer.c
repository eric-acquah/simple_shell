#include "main.h"
/**
 *tokenizer - tokenize a given string
 *@delim: delimeter string
 *@s: string pointer
 *Return: two dimentional array of strings
 */
char **tokenizer(char *s, char *delim)
{
	char *token, **arr;
	int i, j, k, num_tok = 0;

	(void)token;
	(void)arr;
	/* Looping through to skip immediate delim */
	for (i = 0; delim[i] && *s;)
	{
		if (*s == delim[i])
			i = 0, s++;
		else
			i++;
	}
	if (*s != '\0')
		num_tok++;
	num_tok += num_words(s, delim);

	arr = malloc(sizeof(char *) * (num_tok + 1));
	if (arr == NULL)
		return (NULL);
	/* Copy each token into array */
	for (k = 0, i = 0; s[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (s[i] == delim[j])
			{
				arr[k++] = get_token(s, i);
				s += i;
				s = skip_delim(s, delim);
				i = -1;
				break;
			}
		}
		if (s[i + 1] == '\0' && delim[j] == '\0')
			arr[k++] = get_token(s, i + 1);
	}
	arr[k] = NULL;
	return (arr);
}
