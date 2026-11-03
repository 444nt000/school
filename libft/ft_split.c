/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:49:50 by aradix            #+#    #+#             */
/*   Updated: 2026/10/26 14:53:04 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*free_all(char **ret, size_t i)
{
	while (i--)
		free(ret[i]);
	free(ret);
	return (NULL);
}

static char	**fill(char **ret, char const *s, char c)
{
	char const	*start;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			ret[i] = malloc((s - start) + 1);
			if (!ret[i])
				return (free_all(ret, i));
			ft_strlcpy(ret[i], start, (s - start) + 1);
			i++;
		}
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	return (fill(ret, s, c));
}
