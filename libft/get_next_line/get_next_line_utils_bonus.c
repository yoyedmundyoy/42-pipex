/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:48:14 by etong             #+#    #+#             */
/*   Updated: 2024/06/19 09:58:51 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
		return (0);
	i = -1;
	j = -1;
	while (++i < s1len)
		result[i] = s1[i];
	while (++j < s2len)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		++i;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	else
		return (0);
}

char	*parse_result(char *line)
{
	int		i;
	char	*result;

	if (!line[0])
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (0);
	i = -1;
	while (line[++i] && line[i] != '\n')
		result[i] = line[i];
	if (line[i] == '\n')
	{
		result[i] = line[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

char	*parse_new_line(char *line)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (line[i] && line[i] != '\n')
		++i;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	result = malloc(sizeof(char) * (ft_strlen(line) - i));
	if (!result)
		return (0);
	++i;
	j = 0;
	while (line[i])
		result[j++] = line[i++];
	result[j] = '\0';
	free(line);
	return (result);
}
