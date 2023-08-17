#include "main.h"
/**
 * _exit_cmd - function that exit a program
 * @usr_token: pointer to the user's input
 * @av: program name
 * @p_count: prompt count
 * Return: the exit status of the program
 */
int _exit_cmd(char **usr_token, char *av, int p_count, int st)
{
	int res = 0;
	char *p, *str;

	if (usr_token[1] == NULL)
	{
		free_grid(usr_token, 1);
		exit(st);
	}
	for (p = usr_token[1]; *p; p++)
		if (!_isdigit(*p))
		{
			str = num_to_str(p_count);
			write(2, av, strlen(av));
			write(2, ": ", 2);
			write(2, str, strlen(str));
			write(2, ": ", 2);
			write(2, usr_token[0], strlen(usr_token[0]));
			write(2, ": Illegal number: ", 18);
			write(2, usr_token[1], _strlen(usr_token[1]));
			write(2, "\n", 1);
			free(str);
			return (2);
		}
	res = _atoi(usr_token[1]);
	free_grid(usr_token, 1);
	exit(res);
	return (0);
}
