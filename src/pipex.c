#include "pipex.h"

#include <stdio.h>
#include<sys/wait.h>

void exit_message(int exit_code)
{
	// If i = 1, print exit message
	if (exit_code)
		printf("Error message\n");
	exit(0);
}

void execute(char* cmd, char *envp[])
{
	if (cmd || envp)
		ft_putstr_fd("execute", 2);
	// get path
	// get l_cmd
	// execve(path, l_cmd, envp)
	// if execve fails, handle error, print error message, free and exit
}

int try_open(char *argv[], int in_out)
{
	int f;

	if (!in_out)
		f = open(argv[1], O_RDONLY);
	else
		f = open(argv[4], O_CREAT | O_TRUNC | O_RDWR);
	if (f < 0)
		exit(0);
	return (f);
}

void child(char *argv[], char *envp[], int p_fd[])
{
	int f;

	f = try_open(argv, 1);
	if (dup2(f, 1) < 0 || dup2(p_fd[0], 0) < 0)
		exit(0);
	close(p_fd[1]);
	close(f);
	execute(argv[3], envp);
}

void parent(char *argv[], char *envp[], int p_fd[])
{
	int f;

	f = try_open(argv, 0);
	if (dup2(f, 0) < 0 || dup2(p_fd[1], 1) < 0)
		exit(0);
	close(p_fd[0]);
	close(f);
	execute(argv[2], envp);
}

int main(int argc, char *argv[], char *envp[])
{
	int p_fd[2];
	pid_t pid;

	// Check argument count
	// If argument count not 5, return error message
	if (argc != 5)
		exit_message(1);
	// Create pipe
	if (pipe(p_fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (!pid)
		child(argv, envp, p_fd);
	wait(NULL);
	parent(argv, envp, p_fd);

	// Fork
	// If child process, call child function
	// child(argv, envp, p_fd)
	// If parent process, call parent function
	// parent(argv, envp, p_fd)
}

