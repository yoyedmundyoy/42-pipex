/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etong <etong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:43:38 by etong             #+#    #+#             */
/*   Updated: 2024/06/10 07:32:47 by etong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

#include "libft.h"

static int	get_next_start(const char *s, char c, int i)
{
	while (s[i] && s[i] == c)
		++i;
	return (i);
}

static int	get_end(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static char	*create_word(const char *s, int start, int end)
{
	char	*word;
	int		n_char;

	n_char = (end - start + 1);
	word = malloc(sizeof(char) * n_char);
	if (!word)
		return (0);
	ft_strlcpy(word, (char *)s + start, n_char);
	return (word);
}

static char	**append_word(char **result, char *word, int n_words)
{
	char	**new_result;
	int		i;

	new_result = malloc(sizeof(char *) * n_words + 1);
	if (!new_result)
		return (0);
	i = 0;
	while (i < n_words - 1)
	{
		new_result[i] = result[i];
		++i;
	}
	if (n_words)
		new_result[n_words - 1] = word;
	new_result[n_words] = (char *)0;
	if (n_words > 1)
		free(result);
	return (new_result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		n_words;
	int		start;
	int		end;
	char	*word;

	if (!s)
		return (0);
	start = 0;
	n_words = 0;
	start = get_next_start(s, c, start);
	end = get_end(s, c, start);
	while (start != end)
	{
		word = create_word(s, start, end);
		result = append_word(result, word, ++n_words);
		start = end;
		start = get_next_start(s, c, start);
		end = get_end(s, c, start);
	}
	if (!n_words)
		result = append_word(result, 0, n_words);
	return (result);
}
