/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char			*new_buf;
	size_t			i;
	unsigned long	read_buf_size;

	i = 0;
	read_buf_size = (unsigned long)BUFFER_SIZE;
	new_buf = (char *)malloc(buf_size + read_buf_size + 1);
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

static char	*process_buf(int fd, char **buf, ssize_t bytes)
{
	size_t	buf_size;
	ssize_t	nl_pos;

	nl_pos = ft_strchr(*buf, '\n');
	while (nl_pos == -1)
	{
		buf_size = ft_strlen(*buf);
		if (!expand_buf(buf, buf_size))
			return (cleanup(buf));
		bytes = read(fd, *buf + buf_size, BUFFER_SIZE);
		(*buf)[buf_size + bytes] = '\0';
		if (bytes == 0)
			return (get_line(buf, buf_size));
		if (bytes == -1)
			return (cleanup(buf));
		nl_pos = ft_strchr(*buf, '\n');
	}
	return (get_line(buf, nl_pos + 1));
}

char	*get_next_line(int fd)
{
	static char		*buf[FD_BUFFER_SIZE];
	int				bytes;
	unsigned long	read_buf_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_BUFFER_SIZE)
		return (NULL);
	read_buf_size = (unsigned long)BUFFER_SIZE;
	bytes = 0;
	if (!buf[fd])
	{
		buf[fd] = (char *)malloc(read_buf_size + 1);
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	if (!buf[fd][0])
	{
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
			return (cleanup(&buf[fd]));
		buf[fd][bytes] = '\0';
	}
	return (process_buf(fd, &buf[fd], bytes));
}
