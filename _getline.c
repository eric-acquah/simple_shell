#include "main.h"
/**
 *_getline - read from stream
 *@lineptr: pointer to buffer storing the read bytes
 *@fd: file discriptor
 *Return: -1 if EOF or NULL is encountered else return the number of bytes read
 */
int _getline(char **lineptr, int fd)
{
	char ch;
	size_t input_read;
	size_t num = 0;

	*lineptr = _calloc(sizeof(char), 8197);

	input_read = read(fd, &ch, 1);
	while (input_read > 0 && ch != '\n')
	{
		if (num >= 8196)
			break;
		(*lineptr)[num] = ch;
		num++;
		input_read = read(fd, &ch, 1);
	}
	if (input_read <= 0)
		return (-1);
	(*lineptr)[num++] = ch;
	(*lineptr)[num] = '\0';
	*lineptr = _realloc(*lineptr, 8196, (num + 1));
	return (num);
}
