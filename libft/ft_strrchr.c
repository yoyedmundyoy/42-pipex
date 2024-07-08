/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:15:00 by etong             #+#    #+#             */
/*   Updated: 2024/06/05 16:13:45 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found_index;

	i = 0;
	found_index = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			found_index = i;
		++i;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	else if (found_index > -1)
		return ((char *)s + found_index);
	else
		return (0);
}
