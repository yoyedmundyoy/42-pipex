/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:48:17 by etong             #+#    #+#             */
/*   Updated: 2024/06/25 11:19:08 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	result = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = read_file(fd, line);
	if (!line)
		return (NULL);
	result = parse_result(line);
	line = parse_new_line(line);
	return (result);
}
