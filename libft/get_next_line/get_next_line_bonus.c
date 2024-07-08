/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:48:17 by etong             #+#    #+#             */
/*   Updated: 2024/06/25 11:20:27 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// read BUFFER_SIZE bytes from fd and append to line
// and return line when a newline is found
char	*read_file(int fd, char *line)
{
	char	*buffer;
	int		read_result;

	read_result = 1;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(line, '\n') && read_result)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	return (line);
}

// default open files limit in Ubuntu is 1024
// while the default open files limit in CentOS is 4096
char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*result;

	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line[fd] = read_file(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	result = parse_result(line[fd]);
	line[fd] = parse_new_line(line[fd]);
	return (result);
}
