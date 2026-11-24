/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:48:09 by aradix            #+#    #+#             */
/*   Updated: 2026/11/10 16:09:53 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# define MIN_CAPACITY 100

# if BUFFER_SIZE < MIN_CAPACITY
#  define INITIAL_CAPACITY MIN_CAPACITY
# else
#  define INITIAL_CAPACITY BUFFER_SIZE
# endif

typedef struct s_buf
{
	char	*data;
	size_t	capacity;
	size_t	start;
	size_t	end;
}	t_buf;

char	*get_next_line(int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
