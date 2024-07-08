#include "pipex.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd[2];
	int pid1;
	int pid2;

	if (argv)
	{
		;
	}
	if (argc != 5)
		return (1);
	if (pipe(fd) < 0)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
	{
		// Child process 1 (cmd1)
	}
	
	close(fd[0]);
	close(fd[1]);
}
