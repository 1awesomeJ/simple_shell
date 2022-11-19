#include "main.h"


/**
 * main - Main entry point
 *
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: (0) Always Success
 */

int main(int ac, char **av, char **env)
{
	int i;
	(void)ac;
	(void)av;
	i = shell(env);
	return (i);
}
