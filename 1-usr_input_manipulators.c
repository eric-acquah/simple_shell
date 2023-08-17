#include "main.h"
/**
 *validate_cmd - validate user's command and return the path of that cmd
 *@path_token: the tokenized directories of path env variable
 *@usr_input: the users command
 *Return: pointer to validated path for executing cmd
 */
char *validate_cmd(char **path_token, char *usr_input)
{
	int i, valid_size = 1024, stat_flag, a_flag;
	char *valid_path, *valid_clone;
	size_t len = 0;
	struct stat stat_ptr;

#include "relative_path_cmd.h"/*processes user's full path cmds*/
	valid_path = (char *)malloc(sizeof(char) * valid_size);
	if (valid_path == NULL)
		perror("Malloc failed");
	i = 1;
	while (path_token[i] != NULL)
	{
		_strcpy(valid_path, path_token[i]);
		_strcat(valid_path, "/");
		_strcat(valid_path, usr_input);

		stat_flag = stat(valid_path, &stat_ptr);
		a_flag = access(valid_path, X_OK);
		if (stat_flag == 0 && a_flag == 0)
		{
			valid_clone = _strdup(valid_path);
			free(valid_path);
			len = num_of_tokens(path_token);
			free_grid(path_token, len);
			return (valid_clone);
		}
		else if (stat_flag == 0 && a_flag != 0)
		{
			free(valid_path);
			len = num_of_tokens(path_token);
			free_grid(path_token, len);
			return (_strdup("denied"));
		}
		i++;
	}
	valid_clone = _strdup(valid_path);
	free(valid_path);
	len = num_of_tokens(path_token);
	free_grid(path_token, len);
	return (valid_clone);
}
