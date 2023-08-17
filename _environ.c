#include "main.h"

/**
 * _env_cmd - function that prints the current working environment
 * @env: the environment to be printed
 * Return: 0 on success
 */
int _env_cmd(char **env)
{
	size_t i;

	i = 0;
	while (env[i] != NULL)
	{
		write(1, env[i], _strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
