/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:52:59 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/16 03:47:13 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *s, char c)
{
	unsigned int		i;
	unsigned int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	fill_word(char **p, char const *s, char c)
{
	unsigned int		start;
	unsigned int		end;
	unsigned int		j;

	start = 0;
	j = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		p[j] = ft_substr(s, start, end - start);
		if (!p[j])
			return (0);
		j++;
		start = end;
	}
	p[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char				**p;
	size_t				words;
	unsigned int		i;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	p = malloc(sizeof(char *) * (words + 1));
	if (!p)
		return (NULL);
	if (!fill_word(p, s, c))
	{
		i = 0;
		while (i < words && p[i])
		{
			free(p[i]);
			i++;
		}
		free (p);
		return (NULL);
	}
	return (p);
}
