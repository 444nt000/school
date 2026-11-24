/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:25:21 by aradix            #+#    #+#             */
/*   Updated: 2026/11/12 20:02:41 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef union u_val
{
	int			i;
	void		*p;
}				t_val;

typedef struct s_arg
{
	t_val		val;
	int			(*handler)(struct s_arg *arg);
}				t_arg;

typedef int		(*t_handler)(t_arg *arg);

typedef struct s_conv
{
	char		c;
	t_handler	handler;
}				t_conv;

int				ft_printf(const char *fmt, ...);

/* handlers */
int				handle_char(t_arg *arg);
int				handle_str(t_arg *arg);
int				handle_ptr(t_arg *arg);
int				handle_int(t_arg *arg);
int				handle_uint(t_arg *arg);
int				handle_hex_lower(t_arg *arg);
int				handle_hex_upper(t_arg *arg);
int				handle_percent(t_arg *arg);

/* utils */
int				ft_putnbr_base(unsigned long n, const char *base,
					unsigned long base_len);
size_t			ft_strlen(const char *s);

#endif
