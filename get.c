#include "main.h"

/**
  * _getenv - get env value.
  *
  * @name: name of enviroment variable, e.g PATH
  *
  * Return: the value of the enviroment variable passed
  */

char *_getenv(char *name)
{
int i, j;
char *cenv[100];
char *token, *value;
i = j = 0;
while (environ[i] != NULL)
{
	cenv[i] = malloc(sizeof(char) * 2000);
	cenv[i] = _strcpy(cenv[i], environ[i]);
	i++;
}
	cenv[i] = NULL;

	i = 0;
	while (cenv[i] != NULL)
	{
		token = strtok(cenv[i], "=");
		value = strtok(NULL, "\0");
	if (_strcmp(name, token) == 0)
	{
		j = 1;
		break;
	}
	i++;
	}
i = 0;
while (cenv[i] != NULL)
{
	free(cenv[i]);
	i++;
}
	if (j)
	return (value);
	return (NULL);
}

/**
 * _print_env - print current environment variable
 *
 * @env: current env. variable
 *
 * Return: Nothing.
 */

void _print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
}
