#include "main.h"
char * _getenv(char *name)
{
int i , j;
char *cenv[100];
char *token, *value;
i = 0; j = 0;
while(environ[i] != NULL)
{
	cenv[i] = malloc (sizeof(char) * 2000);
	cenv[i] = strcpy(cenv[i], environ[i]);
	i++;
}
	cenv[i] = NULL;

	i = 0;
 	while (cenv[i] != NULL)
	{
		token = strtok(cenv[i], "=");
		value = strtok(NULL, "\0");
	if(strcmp(name, token) == 0)
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

void _print_env(char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}



}
