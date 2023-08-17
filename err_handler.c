#include "main.h"
/**
 *err_handler - Handel error
 *@err_num: error number
 *@program_name: name of the program
 *@err_msg: error message to display
 *@usr_token: user's input command
 *@prompt_count: number of times user was prompted
 *Return: 0 if successful else return 1
 */
int err_handler(int err_num, char *program_name,
		char *usr_token, int prompt_count, char *err_msg)
{
	char *err_str, *num_str;
	int msg_size = 0, msg_buff = 256;

	if (program_name != NULL)
		msg_size += _strlen(program_name);
	if (err_msg != NULL)
		msg_size += _strlen(err_msg);
	if (usr_token != NULL)
		msg_size += _strlen(usr_token);

	num_str = num_to_str(prompt_count);
	if (num_str != NULL)
		msg_size += _strlen(num_str);
	msg_size += 12;

	if (msg_size > msg_buff)
	{
		while (msg_size > msg_buff)
		{
			msg_size *= 2;
		}
	}

	err_str = (char *)malloc(sizeof(char) + msg_size);
	if (err_str == NULL)
		return (1);

#include "processing_err_handler.h"

	free(err_str);
	return (0);
}
