#include "main.h"

/**
 *sigint_handler - handel signal interupt by SIGINT (CTRL-D)
 *@sig_num: sigbal number
 */

void sigint_handler(int sig_num)
{
	(void)sig_num;
	/* Write a newline and a prompt message */
	write(STDOUT_FILENO, SIGINT_MSG, _strlen(SIGINT_MSG));
}

/**
 *sigquit_handler - handel signal interupt by SIGQUIT (CTRL-\)
 *@sig_num: signal number
 */

void sigquit_handler(int sig_num)
{
	/* Ignore the signal number */
	(void)sig_num;

	write(STDOUT_FILENO, SIGQUIT_MSG, _strlen(SIGQUIT_MSG));
}
