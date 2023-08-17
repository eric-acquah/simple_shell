#ifndef EC_SH
#define EC_SH

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>

#define SIGINT_MSG "\nEC_SHELL($) "
#define SIGQUIT_MSG ""
#define BUFF_SIZE 1024

char *linetxt_reader(int fd, size_t buf_siz);

char **tokenizer(char *s, char *delim);

void *_realloc(void *ptr, size_t old_size, size_t new_size);

void *_calloc(unsigned int nmemb, unsigned int size);

char *path_handler(char *usr_cmd, char **env);

int _strlen(char *str);

char *_strcpy(char *dest, char *src);

int num_words(char *s, char *delim);

char *get_token(char *s, int i);

char *skip_delim(char *str, char *delim);

char *_strcat(char *dest, char *src);

int execute(char **usr_token, char *av, int prompt_count, char **env);

char *validate_cmd(char **path_token, char *usr_input);

int err_handler(int err_num, char *pg_name, char *usr_token,
		int prompt_count, char *err_msg);

char *_getenv(char *env[], char *usr_input);

char *skip_obrace(char *cmd);

char *num_to_str(int num);

size_t num_of_tokens(char **toks);

void free_token(char **tokens, size_t len);

void free_grid(char **ptr, size_t size);

int _exit_cmd(char **usr_token, char *av, int p_count, int st);

int _getline(char **lineptr, int fd);

int _strcmp(char *s1, char *s2);

int _env_cmd(char **env);

char *_strdup(char *str);

int _atoi(char *str);

int _isdigit(int c);

void sigint_handler(int sig_num);

void sigquit_handler(int sig_num);

int _cmd_handler(char **usr_token, char *prog_name, int count, char **env, int st);

#endif
