/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 12:26:19 by aradix            #+#    #+#             */
/*   Updated: 2026/10/26 12:43:03 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
