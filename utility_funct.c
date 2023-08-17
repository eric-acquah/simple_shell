#include "main.h"

/**
 * _strdup - function that returns a pointer to a null-terminating byte
 * string pointed to by str
 * @str: pointer to the string to be duplicated
 * Return: a pointer to the newly duplicated string
 */
char *_strdup(char *str)
{
	char *newstr;
	unsigned int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);

	_strcpy(newstr, str);

	return (newstr);
}

/**
 * _atoi - function that converts string into integer
 * @str: string to be converted
 * Return: the converted string
 */
int _atoi(char *str)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (str[len] != '\0')
		len++;
	while (i < len && f == 0)
	{
		if (str[i] == '-')
			++d;
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (n);
}

/**
 *_isdigit - check if value is a number
 *@c: input argument for testing
 *Return: 0 (Success)
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 *skip_obrace - skip the opening braces around a command
 *@cmd: user command
 *Return: the trimed command
 */
char *skip_obrace(char *cmd)
{
	int i;
	char *trim;

	trim = (char *)malloc(sizeof(char) * _strlen(cmd) + 1);
	if (trim == NULL)
		return (NULL);

	if (cmd[0] == '(' && cmd[1] != '\0')
	{
		for (i = 1; cmd[i] != ')' && cmd[i + 1] != '\0'; i++)
		{
			trim[i - 1] = cmd[i];
		}
		trim[i - 1] = '\0';
		return (trim);
	}
	return (NULL);
}
