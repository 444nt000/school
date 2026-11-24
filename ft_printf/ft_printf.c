/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:23:15 by aradix            #+#    #+#             */
/*   Updated: 2026/11/12 19:53:29 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_arg	get_arg(char c, va_list *ap)
{
	static const t_conv	convs[] = {{'c', handle_char}, {'s', handle_str}, {'p',
		handle_ptr}, {'d', handle_int}, {'i', handle_int}, {'u', handle_uint},
	{'x', handle_hex_lower}, {'X', handle_hex_upper}, {'%', handle_percent}, {0,
		NULL}};
	t_arg				arg;
	int					i;

	i = 0;
	while (convs[i].c && convs[i].c != c)
		i++;
	arg.handler = convs[i].handler;
	if (!arg.handler || c == '%')
		return (arg);
	if (c == 's' || c == 'p')
		arg.val.p = va_arg(*ap, void *);
	else
		arg.val.i = va_arg(*ap, int);
	return (arg);
}

static int	print_conv(char c, va_list *ap)
{
	t_arg	arg;

	arg = get_arg(c, ap);
	if (!arg.handler)
		return (-1);
	return (arg.handler(&arg));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!fmt)
		return (-1);
	count = 0;
	ret = 0;
	va_start(ap, fmt);
	while (count >= 0 && *fmt)
	{
		if (*fmt == '%')
			ret = print_conv(*++fmt, &ap);
		else
			ret = write(1, fmt, 1);
		if (ret < 0)
			count = -1;
		else
			count += ret;
		fmt++;
	}
	va_end(ap);
	return (count);
}
