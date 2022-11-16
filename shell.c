#include "main.h"
int main(int __attribute__((unused))ac, char __attribute__((unused))**av, char **env)
{
	ssize_t read_line;
        char *token, *buffer, *path = NULL;
        size_t n = 0;
	int i, k, status, terminal;
	char *args[100], *envp[] = {NULL};
	pid_t pid;
	struct stat st;

        read_line = 0;
	terminal = 1;
	while (terminal)
        {
		i = 0;
		terminal = isatty(STDIN_FILENO);
		write(STDOUT_FILENO, "#Cisfun$ ", 10);
		read_line = getline(&buffer, &n, stdin);
		if (read_line == -1)
		{
			printf("logout\n");
			return (0);
		}
		token = strtok(buffer, "\n");
		token = strtok(token, " ");

		while(token)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if ((strcmp(args[0], "exit") == 0)) exit(EXIT_SUCCESS);
		
		if ((strcmp(args[0], "env") == 0)) 
		{	_print_env(env);
			continue;
		}

		if (stat(args[0], &st) == 0)
			path = args[0];
		else
			path = findpath(args[0]);
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
		wait(&status);

        }

        return (0);
}
