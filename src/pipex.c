#include "pipex.h"

#include <stdio.h>
#include <sys/wait.h>

void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

char *find_path(char* cmd, char *envp[])
{
	char **env_paths;
	char *temp_path;
	char *path;
	int i;
	
	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		++i;
	env_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		temp_path = ft_strjoin(env_paths[i], "/");
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (!access(path, F_OK | X_OK))
		{
			free_arr(env_paths);
			return(path);
		}
		free(path);
		++i;
	}
	free_arr(env_paths);
	return (0);
}

void execute(char* cmd, char *envp[])
{
	char **l_cmd;
	char *path;

	l_cmd = ft_split(cmd, ' ');
	path = find_path(l_cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(l_cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_arr(l_cmd);
		free(path);
		exit(1);
	}
	if (execve(path, l_cmd, envp) < 0)
	{
		free_arr(l_cmd);
		free(path);
		exit(0);
	}
}

void child(char *argv[], char *envp[], int p_fd[])
{
	int f_in;

	f_in = open(argv[1], O_RDONLY, 0777);
	if (f_in < 0)
	{
		ft_printf("pipex: %s: No such file or directory\n", argv[1]);
		exit(1);
	}
	dup2(f_in, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute(argv[2], envp);
}

void parent(char *argv[], char *envp[], int p_fd[])
{
	int f_out;

	f_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (f_out < 0)
		exit(1);
	dup2(f_out, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	execute(argv[3], envp);
}

int main(int argc, char *argv[], char *envp[])
{
	int p_fd[2];
	pid_t pid;

	if (argc != 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	if (pipe(p_fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (!pid)
		child(argv, envp, p_fd);
	wait(NULL);
	parent(argv, envp, p_fd);
}

