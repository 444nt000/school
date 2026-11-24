/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <444nt000@proton.me>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:47:25 by aradix            #+#    #+#             */
/*   Updated: 2026/11/10 16:16:21 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	grow_buf(t_buf *buf)
{
	char	*new;
	size_t	new_capacity;

	if (buf->capacity > (size_t)-1 / 2)
		return (false);
	new_capacity = buf->capacity * 2;
	if (new_capacity < buf->end + BUFFER_SIZE)
		new_capacity = buf->end + BUFFER_SIZE;
	new = malloc(new_capacity);
	if (!new)
		return (false);
	ft_memmove(new, buf->data, buf->end);
	free(buf->data);
	buf->data = new;
	buf->capacity = new_capacity;
	return (true);
}

static bool	ensure_room(t_buf *buf)
{
	if (!buf->data)
	{
		buf->data = malloc(INITIAL_CAPACITY);
		buf->capacity = INITIAL_CAPACITY;
		return (buf->data != NULL);
	}
	if (buf->start > 0)
	{
		ft_memmove(buf->data, buf->data + buf->start, buf->end - buf->start);
		buf->end -= buf->start;
		buf->start = 0;
	}
	if (buf->end + BUFFER_SIZE > buf->capacity)
		return (grow_buf(buf));
	return (true);
}

static char	*extract_line(t_buf *buf, size_t len)
{
	char	*line;

	if (len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memmove(line, buf->data + buf->start, len);
	line[len] = '\0';
	buf->start += len;
	return (line);
}

static void	*free_buf(t_buf *buf)
{
	free(buf->data);
	buf->data = NULL;
	buf->capacity = 0;
	buf->start = 0;
	buf->end = 0;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_buf	buf;
	char			*line;
	char			*tmp;
	ssize_t			nb_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		tmp = ft_memchr(buf.data + buf.start, '\n', buf.end - buf.start);
		if (tmp)
			return (extract_line(&buf, tmp - (buf.data + buf.start) + 1));
		if (!ensure_room(&buf))
			return (free_buf(&buf));
		nb_read = read(fd, buf.data + buf.end, BUFFER_SIZE);
		if (nb_read < 0)
			return (free_buf(&buf));
		if (nb_read == 0)
		{
			line = extract_line(&buf, buf.end - buf.start);
			free_buf(&buf);
			return (line);
		}
		buf.end += nb_read;
	}
}
