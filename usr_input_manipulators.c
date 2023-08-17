#include "main.h"

/**
 *linetxt_reader - reads text line from standard input
 *@fd: file discriptor
 *@buf_siz: size of buffer
 *Return: pointer to a text buffer
 */

char *linetxt_reader(int fd, size_t buf_siz)
{
	char *txt_buff = NULL;
	int getline_stat;

	(void)buf_siz;
	fflush(stdout);
	getline_stat = _getline(&txt_buff, fd);
	if (getline_stat == -1)
	{
		free(txt_buff);
		return (NULL);
	}
	return (txt_buff);
}
