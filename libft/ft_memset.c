/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:08:29 by etong             #+#    #+#             */
/*   Updated: 2024/06/05 09:43:02 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *) b)[i] = uc;
		++i;
	}
	return (b);
}
