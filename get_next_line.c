/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*cleanup(char **buf)
{
	if (*buf != NULL)
		free(*buf);
	*buf = NULL;
	return (NULL);
}

static char	*get_line(char **p_buf, size_t end)
{
	char	*tmp;
	char	*buf;
	size_t	i;

	buf = *p_buf;
	i = 0;
	tmp = ft_strndup(buf, end);
	if (!tmp)
		return (cleanup(p_buf));
	while (buf[end])
		buf[i++] = buf[end++];
	while (buf[i])
		buf[i++] = '\0';
	return (tmp);
}

static char	*expand_buf(char **buf, size_t buf_size)
{
	char	*new_buf;
	size_t	i;

	i = 0;
	new_buf = (char *)malloc(buf_size + BUFFER_SIZE + 1);
	if (!new_buf)
		return (cleanup(buf));
	while ((*buf)[i])
	{
		new_buf[i] = (*buf)[i];
		i++;
	}
	new_buf[i] = '\0';
	free(*buf);
	*buf = new_buf;
	return (new_buf);
}

static char	*work(int fd, char **buf)
{
	size_t	buf_size;
	ssize_t	bytes;
	ssize_t	nl_pos;

	if (!(*buf)[0])
	{
		bytes = read(fd, *buf, BUFFER_SIZE);
		if (!bytes)
			return (cleanup(buf));
		(*buf)[bytes] = '\0';
	}
	nl_pos = ft_strchr(*buf, '\n');
	while (nl_pos == -1)
	{
		buf_size = ft_strlen(*buf);
		if (!expand_buf(buf, buf_size))
			return (cleanup(buf));
		bytes = read(fd, &(*buf)[buf_size], BUFFER_SIZE - buf_size);
		(*buf)[buf_size + bytes] = '\0';
		if (bytes == 0)
			return (get_line(buf, buf_size));
		if (!bytes)
			return (cleanup(buf));
		nl_pos = ft_strchr(*buf, '\n');
	}
	return (get_line(buf, nl_pos + 1));
}

char	*get_next_line(int fd)
{
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	return (work(fd, &buf));
}
