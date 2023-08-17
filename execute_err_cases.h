#ifndef CASES
#define CASES

if (usr_token == NULL)
	return (0);

path_token = _getenv(env);

valid_path = validate_cmd(path_token, usr_token[0]);

	denied = _strcmp(valid_path, "denied");
	if (denied == 0)
		err_handler(13, av, usr_token[0], p_count, NULL);

#endif
