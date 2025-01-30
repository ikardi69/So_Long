/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:03:15 by mteffahi          #+#    #+#             */
/*   Updated: 2025/01/30 16:21:12 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		// if (s[i] != c && !in_word) // Start of a new word
		// {
		// 	count++;
		// 	in_word = 1;
		// }
		// else if (s[i] == c) // Outside a word
		// 	in_word = 0;
		i++;
	}
	return (count);
}

static char	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	char	**ft_alloc(char **words, char const *s, char c, size_t size)
{
	size_t	end;
	size_t	start;
	size_t	k;

	start = 0;
	end = 0;
	k = 0;
	while (s[end] != '\0' && k < size)
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (end > start)
		{
			words[k] = ft_substr(s, start, (end - start));
			if (!words[k])
				return (ft_free(words));
			start = end + 1;
			k++;
		}
	}
	words[k] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**words;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (ft_free(words));
	words = ft_alloc(words, s, c, count + 1);
	if (!words)
		return (ft_free(words));
	return (words);
}
