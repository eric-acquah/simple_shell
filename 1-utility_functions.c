#include "main.h"
/**
 *_realloc - resize a memory block
 *@ptr: pointer to prevoius memory block
 *@new_size: size of new memory block
 *@old_size: size of prevoius memory block
 *Return: pointer to new memory block
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned int j;
	void *resize;
	char *old_clone;
	char *new_clone;

	if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	resize = malloc(new_size);
	if (resize == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		free(ptr);
		ptr = resize;
	}
	else if (ptr != NULL)
	{
		new_clone = (char *)resize;
		old_clone = (char *)ptr;

		for (j = 0; j < new_size && j < old_size; j++)
			new_clone[j] = old_clone[j];

		free(ptr);
	}
	return (resize);
}
/**
 *num_of_tokens - return the number of tokens within a 2d array
 *@toks: a pointer to the 2d array
 *Return: number of tokens read
 */

size_t num_of_tokens(char **toks)
{
	size_t tok_count;

	if (toks == NULL)
		return (0);
	tok_count = 0;
	while (toks[tok_count] != NULL)
		tok_count++;
	return (tok_count);
}
