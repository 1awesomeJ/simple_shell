#include "main.h"

/**
 * shell - Inbuilt shell
 *
 * @env: environment variable
 *
 * Return: (0) always success
 */

int shell(char **env)
{
	ssize_t read_line;
	char *token, *buffer, *path, *r, *args[100], *envp[100];
	size_t n;
	int i, k, status, terminal;
	pid_t pid;
	struct stat st;

	read_line = n = i = 0;
	while(env[i])
	{
		envp[i] = env[i];
		i++;
	}
	terminal = 1;
	envp[i] = r = path = token = buffer = NULL;
	while (terminal)
	{
		i = 0;
		terminal = isatty(STDIN_FILENO);
			if (terminal)
		write(STDOUT_FILENO, "($) ", 4);
		read_line = getline(&buffer, &n, stdin);
		if (read_line == -1)
		{
			printf("logout\n");
			free(buffer);
			if (r != NULL)
				free (r);
			return (0);
		}
		if (_strcmp(buffer, "\n") == 0)
			continue;
		token = strtok(buffer, "\n");
		if (_strcmp(token, " ") == 0)
			continue;
		token = strtok(token, " ");
		while (token)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
		if (_strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			if (r != NULL)
				free(r);
			exit(2);
		}
		if ((_strcmp(args[0], "env") == 0))
		{	_print_env(env);
			continue;
		}

		if (stat(args[0], &st) == 0)
			path = args[0];
		else
		{
			r = findpath(args[0]);
			path = r;
		}
		if (path == NULL)
		{
			printf("%s: Command not found\n", args[0]);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			k = execve(path, args, envp);
			if (k == -1)
				printf("%s: Command not found\n", args[0]);
		}
		else
		{
			wait(&status);
		}

	}
	free(buffer);
	free(r);
	return (0);
}
