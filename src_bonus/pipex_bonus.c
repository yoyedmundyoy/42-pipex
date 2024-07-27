#include "pipex_bonus.h"

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

void exec_pipe(char* cmd, char *envp[])
{
	int p_fd[2];
	pid_t pid;

	if (pipe(p_fd) < 0)
		exit(1);
	pid = fork();
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		execute(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
	}
}

void here_doc(int argc, char *delimiter)
{
	pid_t pid;
	int p_fd[2];
	char *line;

	if (argc < 6)
		exit(1);
	if (pipe(p_fd) < 0)
		exit(1);
	pid = fork();
	if (!pid)
	{
		close(p_fd[0]);
		while (1)
		{
			line = get_next_line(0);
			if (ft_strcmp(line, delimiter) == '\n')
			{
				free(line);
				exit(0);
			}
			ft_putstr_fd(line, p_fd[1]);
			free(line);
		}
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	int i;
	int f_in;
	int f_out;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2");
		exit(1);
	}
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		i = 3;
		f_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		printf("Delimiter: %s\n", argv[2]);
		here_doc(argc, argv[2]);
	}
	else
	{
		i = 2;
		f_in = open(argv[1], O_RDONLY, 0777);
		if (f_in < 0)
		{
			ft_printf("pipex: %s: No such file or directory\n", argv[1]);
			exit(1);
		}
		f_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(f_in, STDIN_FILENO);
	}
	while (i < argc - 2)
		exec_pipe(argv[i++], envp);
	dup2(f_out, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
}

