/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:59:29 by etong             #+#    #+#             */
/*   Updated: 2024/06/07 14:30:46 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if ((long) count < 0 && (long) size < 0)
		return (0);
	result = malloc(count * size);
	if (!result)
	{
		free(result);
		return (0);
	}
	ft_memset(result, 0, count * size);
	return (result);
}
