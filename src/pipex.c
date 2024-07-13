#include "pipex.h"

#include <stdio.h>

void exit_message(int exit_code)
{
	// If i = 1, print exit message
	if (exit_code)
	
	// Exit
}

void execute(char* cmd, char *envp[])
{
	// get path
	// get l_cmd
	// execve(path, l_cmd, envp)
	// if execve fails, handle error, print error message, free and exit
}

void child(char *argv[], char *envp[], int p_fd[])
{
	// Try to open the in file
	// dup2 so infile becomes fd stdin 0
	// dup2 so p_fd[1] (write end) becomes stdout 1
	// execute function
}

void parent(char *argv[], char *envp[], int p_fd[])
{
	// Try to open the in file
	// dup2 so infile becomes fd stdin 0
	// dup2 so p_fd[1] (write end) becomes stdout 1
	// execute function
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
	// If pipe creation fails exit
	// Fork
	// If child process, call child function
	// child(argv, envp, p_fd)
	// If parent process, call parent function
	// parent(argv, envp, p_fd)
}

