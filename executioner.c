#include "main.h"
/**
 * execute - function that execute the command line arguments
 * @usr_token: the array of argument to be entered
 * @av: argument vector
 * @p_count: a count of how many times usr is prompted for input
 * @env: environment variable
 * Return: the number of argument entered
 */
int execute(char **usr_token, char *av, int p_count, char **env)
{
	int status;
	pid_t cid;

	(void)av;
	(void)p_count;

	cid = fork();
	if (cid == -1)
		perror("fork");
	else if (cid == 0)
	{
		execve(usr_token[0], usr_token, env);
		exit(1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return (status);
}
