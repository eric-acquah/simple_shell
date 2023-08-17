#ifndef FULL_PATH
#define FULL_PATH

if (usr_input[0] == '.' || usr_input[0] == '/' || usr_input[0] == '(')
{
	if (usr_input[0] == '(')
		usr_input = skip_obrace(usr_input);

	stat_flag = stat(usr_input, &stat_ptr);
	a_flag = access(usr_input, X_OK);

	if (stat_flag == 0 && a_flag == 0)
	{
		len = num_of_tokens(path_token);
		free_grid(path_token, len);
		return (_strdup(usr_input));
	}
	else if (stat_flag == 0 && a_flag != 0)
	{
		len = num_of_tokens(path_token);
		free_grid(path_token, len);
		return (_strdup("denied"));
	}
	else
	{
		len = num_of_tokens(path_token);
		free_grid(path_token, len);
		return (_strdup(usr_input));
	}
	len = num_of_tokens(path_token);
	free_grid(path_token, len);
}

#endif
