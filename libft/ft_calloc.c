/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:46:25 by aradix            #+#    #+#             */
/*   Updated: 2026/11/04 12:49:16 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*new;

	if (size > 0 && n > (size_t)-1 / size)
		return (NULL);
	new = malloc(n * size);
	if (!new)
		return (NULL);
	ft_bzero(new, n * size);
	return (new);
}
