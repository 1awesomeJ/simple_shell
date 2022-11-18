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
	(void)ac;
	(void)av;
	shell(env);
	return (0);
}
