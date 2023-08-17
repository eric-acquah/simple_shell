#include "main.h"

/**
 *_strlen - get the length of strings
 *@str: string input
 *Return: length of the given string
 */
int _strlen(char *str)
{
	int counter;

	for (counter = 0; str[counter] != '\0';)
		counter++;

	return (counter);
}

/**
 * _strcpy - function that copies string to another
 * @dest: the destination of the string
 * @src: the soucre of the string
 * Return: return the number of the string copied
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function the combine strings together
 * @dest: the string destination
 * @src: the string source
 * Return: return the combined string
 */
char *_strcat(char *dest, char *src)
{
	int i, j, len = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		len++;
	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[len + j] = src[j];
	}
	dest[len + j] = '\0';
	return (dest);
}

/**
 *free_grid - free two dimentional arrays
 *@ptr: pointer to the 2D array
 *@size: size of each substring string
 */
void free_grid(char **ptr, size_t size)
{
	size_t i;
	(void)size;

	if (ptr == NULL)
		return;
	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}
/**
 * _strcmp - function that compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: strings compared
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] - s2[x]);
		}
		x++;
	}
	return (0);
}
