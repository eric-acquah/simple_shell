#include "main.h"

/**
 *path_handler - handel path
 *@usr_cmd: usr command input
 *@env: envrion value
 *Return: path token
 */

char *path_handler(char *usr_cmd, char **env)
{
	char *valid_buf;
	char *path, **path_token;
	int i;
	struct stat ptr;


	valid_buf = (char *)_calloc(sizeof(char), 1024);

	path = _getenv(env, "PATH");

	path_token = tokenizer(path, ":");

	i = 0;
	while (path_token[i] != NULL)
	{
		_strcpy(valid_buf, path_token[i]);
		_strcat(valid_buf, "/");
		_strcat(valid_buf, usr_cmd);

		if (stat(valid_buf, &ptr) == 0)
		{
			free_grid(path_token, 0);
			return (valid_buf);
		}
		i++;
	}
	free_grid(path_token, 0);
	free(valid_buf);
	return (NULL);
}
