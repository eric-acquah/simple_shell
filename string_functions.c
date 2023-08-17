#include "main.h"
/**
 *word_counter - return the number of words within a given str
 *@str: pointer to array of words
 *@str_len: the actual length of string
 *Return: number of words else zero if an error occured
 */
ssize_t word_counter(char *str, int str_len)
{
	ssize_t i, s_len, count = 0;
	int inword = 0;

	if (str == NULL)
		return (0);

	s_len = (ssize_t)str_len;
	while (str[0] == ' ')/* Trim leading spaces from str array */
	{
		str++;
		s_len--;
	}
	while (str[s_len - 1] == ' ')/* Trim trailing spaces from str array */
		s_len--;
	/* Iterate over str array */
	for (i = 0; i < s_len; i++)
	{
		/* Check if current character is a space */
		if (str[i] == ' ')
		{
			/* Check if inside a word */
			if (inword)
			{
				/* Increment count and reset flag */
				count++;
				inword = 0;
			}
		}
		else /* current character is not a space */
		{
			 /* Set flag to indicate inside a word */
			inword = 1;
		}
	}
	/* Check if last character was part of a word */
	if (inword)
		count++;

	return (count);
}
