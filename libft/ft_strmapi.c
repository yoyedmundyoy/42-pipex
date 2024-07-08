/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:49:56 by etong             #+#    #+#             */
/*   Updated: 2024/06/06 14:25:31 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (0);
	count = ft_strlen(s);
	result = ft_calloc(count + 1, sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i < count)
	{
		result[i] = f(i, s[i]);
		++i;
	}
	return (result);
}
