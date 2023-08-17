#include "main.h"
/**
 * _cmd_handler - function that handles the builtin commands.
 * @usr_token: the user's input.
 * @prog_name: the program's name
 * @count: the counter for the user's input
 * @env: the environment variable
 * Return: the command's output
 */
int _cmd_handler(char **usr_token, char *prog_name, int count, char **env, int st)
{
	char *path_received, *str;
	struct stat ptr;

	if (!_strcmp(usr_token[0], "exit"))
		return (_exit_cmd(usr_token, prog_name, count, st));
	else if (!_strcmp(usr_token[0], "env") && usr_token[1] == NULL)
		return (_env_cmd(env));
	else
	{
		if (stat(usr_token[0], &ptr) == 0)
			return (execute(usr_token, prog_name, count, env));
		else
		{
			path_received = path_handler(usr_token[0], env);
			if (path_received != NULL)
			{
				free(usr_token[0]);
				usr_token[0] = path_received;
				return (execute(usr_token, prog_name, count, env));
			}
		}

	}
	str = num_to_str(count);
	write(2, prog_name, strlen(prog_name));
	write(2, ": ", 2);
	write(2, str, strlen(str));
	write(2, ": ", 2);
	write(2, usr_token[0], strlen(usr_token[0]));
	write(2, ": not found\n", 12);
	free(str);
	return (127);
}
