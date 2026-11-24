/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:41:59 by aradix            #+#    #+#             */
/*   Updated: 2026/11/23 10:05:46 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex_lower(t_arg *arg)
{
	unsigned int	n;

	n = arg->val.i;
	return (ft_putnbr_base(n, "0123456789abcdef", 16));
}

int	handle_hex_upper(t_arg *arg)
{
	unsigned int	n;

	n = arg->val.i;
	return (ft_putnbr_base(n, "0123456789ABCDEF", 16));
}
