/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:41:59 by aradix            #+#    #+#             */
/*   Updated: 2026/11/23 10:21:37 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_ptr(t_arg *arg)
{
	unsigned long	n;
	int				ret;

	if (!arg->val.p)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	n = (unsigned long)arg->val.p;
	ret = ft_putnbr_base(n, "0123456789abcdef", 16);
	if (ret == -1)
		return (-1);
	return (ret + 2);
}
