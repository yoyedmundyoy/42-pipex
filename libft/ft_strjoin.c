/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:01:05 by etong             #+#    #+#             */
/*   Updated: 2024/06/05 16:39:53 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

#include "libft.h"

static void	copy_to_result(char const *s1, char const *s2, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		result[i] = s1[j];
		++i;
		++j;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		++i;
		++j;
	}
	result[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	result = malloc((s1len + s2len + 1) * sizeof(char));
	if (!result)
		return (0);
	copy_to_result(s1, s2, result);
	return (result);
}
