/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:15:15 by aradix            #+#    #+#             */
/*   Updated: 2026/11/12 20:03:32 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, const char *base, unsigned long base_len)
{
	int	count;

	count = 0;
	if (n >= base_len)
	{
		count = ft_putnbr_base(n / base_len, base, base_len);
		if (count == -1)
			return (-1);
	}
	if (write(1, &base[n % base_len], 1) == -1)
		return (-1);
	return (count + 1);
}
