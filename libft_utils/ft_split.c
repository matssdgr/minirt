/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:38:53 by amrakouk          #+#    #+#             */
/*   Updated: 2026/11/09 12:36:47 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_utils.h"

static int	safe_malloc(char **words, int pos, size_t buff)
{
	int	i;

	i = 0;
	words[pos] = malloc(buff);
	if (!words[pos])
	{
		while (i < pos)
		{
			free(words[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static size_t	count_words(char const *s, char del)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == del && *s)
			s++;
		if (*s && *s != del)
		{
			count++;
			while (*s != del && *s)
				s++;
		}
	}
	return (count);
}

static int	fill_words(char **words, char const *s, char del)
{
	size_t		len;
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s == del && *s)
			s++;
		start = s;
		len = 0;
		while (*s != del && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (safe_malloc(words, i, len + 1))
				return (1);
			ft_strlcpy(words[i], start, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	if (fill_words(words, s, c))
	{
		free(words);
		return (NULL);
	}
	words[count] = NULL;
	return (words);
}
