/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:59:00 by etong             #+#    #+#             */
/*   Updated: 2024/06/05 16:12:26 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!n && !haystack)
		return (0);
	i = 0;
	while (haystack[i] && i < n)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j] && i + j < n)
		{
			if (!needle[j + 1])
				return ((char *)haystack + i);
			++j;
		}
		++i;
	}
	if (!needle[0])
		return ((char *)haystack);
	else
		return (NULL);
}
