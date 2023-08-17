#ifndef PROCESS
#define PROCESS

if (err_msg != NULL && program_name != NULL)
{
	_strcpy(err_str, program_name);
	_strcat(err_str, ": ");
	_strcat(err_str, num_str);
	_strcat(err_str, ": ");
	_strcat(err_str, usr_token);
	_strcat(err_str, ": ");
	_strcat(err_str, err_msg);
	_strcat(err_str, "\n");
	write(STDERR_FILENO, err_str, (msg_size - 5));
	free(err_str);
	free(num_str);
	exit(0);
}
else if (err_num != 0)
{
	_strcpy(err_str, program_name);
	_strcat(err_str, ": ");
	_strcat(err_str, num_str);
	_strcat(err_str, ": ");
	_strcat(err_str, usr_token);
	switch (err_num)
	{
	case 20:
		errno = 20;
		perror(err_str);
		break;
	case 21:
		errno = 21;
		perror(err_str);
		break;
	case 2:
		errno = 2;
		perror(err_str);
		break;
	case 13:
		errno = 13;
		perror(err_str);
		break;
	}
}
else
{
	free(err_str);
	return (1);
}

#endif
