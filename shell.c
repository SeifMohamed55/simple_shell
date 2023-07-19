#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"
#include <sys/wait.h>
#define LINELEN 1000

int is_all_spaces(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
/**
 * main - runs the shell program
 * @argc: number of params
 * @argv: array of strings (parameters)
 *
 * Return: 0 on normal termination
 */
int main(int argc, char **argv)
{
	char *c = 0, *token = 0, *exerror = "1: exit: Illegal number: ";
	const char so[] = " ";
	size_t len = 0;
	int stat = 0;
	int x = 0, res, pipe = isatty(0), i = 0, j;
	pid_t pid;
	char **arg = malloc(sizeof(char*) * 5);

	while (1)
	{
		argv = argv;
		argc = argc;
		if(pipe)
			write(STDOUT_FILENO,"#lolxD ", 7);
		x = getline(&c, &len, stdin);
		if (x == -1) break;
		if (_strlen(c) == 1 && c[0] == '\n') continue;
		if (c[_strlen(c) - 1] == '\n')c[_strlen(c) - 1] = 0;
		if (is_all_spaces(c)) continue;

		i = 0;
		token = _strtok(c, so);
		while (token != NULL)
		{
			arg[i] = (char*)malloc(_strlen(token) * sizeof(char) + 2);
			j = 0;
			while (token[j])
			{
				arg[i][j] = token[j];
				j++;
			}
			arg[i][j] = '\0';
			i++;
			token = _strtok(NULL, so);
		}
		arg[i] = NULL;
		if (arg[0][0] == 'e' && arg[0][1] == 'x' && arg[0][2] == 'i' && arg[0][3] == 't' && arg[0][4] == '\0')
		{
			free(c);
			c = NULL;
			myexit(arg, WEXITSTATUS(stat));
			write(2,argv[0],_strlen(argv[0]));
			write(2, ": ", 2);
			write(2, exerror, _strlen(exerror));
			write(2, arg[1], _strlen(arg[1]));
			write(2, "\n", 1);
			stat = (2 << 8);
			free2D(arg);
			continue;
		}
		if (arg[0][0] == 'e' && arg[0][1] == 'n'  && arg[0][2] == 'v' && arg[0][3] == '\0')
		{
			int x = 0;
			while (environ[x] != NULL)
			{
				write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
				write(STDOUT_FILENO, "\n", 1);
				x++;
			}
			free2D(arg);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			res = execve(arg[0], arg, environ);
			if (res == -1)
				write(STDOUT_FILENO, "No such command\n", 16);
			exit(127);
		}
		wait(&stat);
		free2D(arg);
	}
	if (c)
		free(c);
	if (arg) 
		free(arg);
	exit(WEXITSTATUS(stat));
}
