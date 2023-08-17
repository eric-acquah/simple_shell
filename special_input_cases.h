#ifndef UNIQ
#define UNIQ

if ((valid_path[0] == '.') && (valid_path[1] == '/') &&
(valid_path[2] == '\0'))
{
	free(valid_path);
	err_handler(13, av, usr_token[0], p_count, NULL);
	return (0);
}
else if (valid_path[0] == '/' && valid_path[1] == '\0')
{
	free(valid_path);
	err_handler(13, av, usr_token[0], p_count, NULL);
	return (0);
}

#endif
