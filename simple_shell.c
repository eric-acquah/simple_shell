#include "main.h"
/**
 *main - interprete command line programs
 *@ac: argument count
 *@av: argument vector
 *@env: environment variables
 *Return: 0 (Success)
 */
int main(int ac, char *av[], char *env[])
{
	size_t input_byts = 0;
	int p_count;
	char *read_buff, **parsed_txt, *msg = "EC_SHELL($) ";
	char new_line = '\n';
	int st = 0;

	(void)ac;
	(void)input_byts;
	p_count = 1;
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, msg, _strlen(msg));/*Prompt for input*/
		read_buff = linetxt_reader(STDIN_FILENO, input_byts);
		if (read_buff == NULL)
		{
			free(read_buff);
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, &new_line, 1);
			break;
		}
		parsed_txt = tokenizer(read_buff, " \n");
		free(read_buff);
		if (parsed_txt == NULL || parsed_txt[0] == NULL)
		{
			if (parsed_txt != NULL)
				free_grid(parsed_txt, 0);
			continue;
		}
		st = _cmd_handler(parsed_txt, av[0], p_count, env, st);
		free_grid(parsed_txt, 0);
		p_count++;
	}
	return (st);
}
