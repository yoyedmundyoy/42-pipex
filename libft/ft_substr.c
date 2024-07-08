/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:51 by etong             #+#    #+#             */
/*   Updated: 2024/06/07 14:35:12 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		result = malloc((ft_strlen(s) + 1) * sizeof(char));
	else
		result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	if (start >= ft_strlen((char *)s))
		result[0] = '\0';
	else
		ft_strlcpy(result, (char *)s + start, len + 1);
	return (result);
}
