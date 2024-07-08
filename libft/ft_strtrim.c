/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:40 by etong             #+#    #+#             */
/*   Updated: 2024/06/06 09:32:15 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

#include "libft.h"

static int	char_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		++set;
	}
	return (0);
}

// Function to find and return start index
static int	find_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!char_in_set(s1[i], set))
			return (i);
		++i;
	}
	return (-1);
}

// Function to find and return end index
static int	find_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (!char_in_set(s1[i], set))
			return (i);
		--i;
	}
	return (-1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start_idx;
	int		end_idx;
	char	*result;
	int		result_size;

	if (!s1 || !set)
		return (0);
	start_idx = find_start(s1, set);
	end_idx = find_end(s1, set);
	result_size = (end_idx - start_idx + 2);
	result = malloc(sizeof(char) * result_size);
	if (!result)
		return (0);
	ft_strlcpy(result, (char *)s1 + start_idx, result_size);
	return (result);
}
