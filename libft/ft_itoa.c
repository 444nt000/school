/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:03:36 by aradix            #+#    #+#             */
/*   Updated: 2026/10/19 12:38:02 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n <= -10 || n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;
	bool	neg;

	neg = (n < 0);
	size = count_digits(n);
	ret = malloc(size + 1);
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	while (size-- > neg)
	{
		if (neg)
			ret[size] = -(n % 10) + '0';
		else
			ret[size] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
