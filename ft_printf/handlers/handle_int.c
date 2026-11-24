/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:41:59 by aradix            #+#    #+#             */
/*   Updated: 2026/11/12 19:23:59 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_int(t_arg *arg)
{
	long	n;
	int		ret;

	n = arg->val.i;
	if (n >= 0)
		return (ft_putnbr_base(n, "0123456789", 10));
	if (write(1, "-", 1) == -1)
		return (-1);
	ret = ft_putnbr_base(-n, "0123456789", 10);
	if (ret == -1)
		return (-1);
	return (ret + 1);
}
