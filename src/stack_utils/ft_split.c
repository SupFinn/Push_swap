/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhssayn <rhssayn@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:52:59 by rhssayn           #+#    #+#             */
/*   Updated: 2025/12/19 04:17:41 by rhssayn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	count_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			size;
	size_t			slen;
	unsigned int	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		size = 0;
	else if (slen - start < len)
		size = slen - start;
	else
		size = len;
	p = malloc(size + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	fill_word(char **p, char const *s, char c)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	j;

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
	char			**p;
	size_t			words;
	unsigned int	i;

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
		free(p);
		return (NULL);
	}
	return (p);
}
