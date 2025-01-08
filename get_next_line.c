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

static void	cleanup(char **tupile)
{
	free(tupile[0]);
	free(tupile[1]);
}

static char	*get_line(char **tupile, ssize_t nl_pos)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strndup(tupile[0], ++nl_pos);
	if (!tmp)
		return (cleanup(tupile), NULL);
	free(tupile[1]);
	tupile[1] = tmp;
	while (tupile[0][nl_pos])
		tupile[0][i++] = tupile[0][nl_pos++];
	while (tupile[0][i])
		tupile[0][i++] = '\0';
	return (tmp);
}

static int	expand_buf(char **tupile, size_t buf_size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(buf_size + BUFFER_SIZE + 1);
	if (!tmp)
		return (-1);
	while (tupile[0][i])
	{
		tmp[i] = tupile[0][i];
		i++;
	}
	tmp[i] = '\0';
	free(tupile[0]);
	tupile[0] = tmp;
	return (0);
}

static char	*work(int fd, char **tupile)
{
	size_t	buf_size;
	ssize_t	bytes;
	ssize_t	nl_pos;

	if (!tupile[0][0])
	{
		bytes = read(fd, tupile[0], BUFFER_SIZE);
		if (!bytes)
			return (cleanup(tupile), NULL);
	}
	nl_pos = ft_strchr(tupile[0], '\n');
	while (nl_pos == -1)
	{
		buf_size = ft_strlen(tupile[0]);
		if (expand_buf(tupile, buf_size) == -1)
			return (cleanup(tupile), NULL);
		bytes = read(fd, &tupile[0][buf_size], BUFFER_SIZE - buf_size);
		if (bytes == 0)
			return (get_line(tupile, buf_size - 1));
		if (!bytes)
			return (cleanup(tupile), NULL);
		nl_pos = ft_strchr(tupile[0], '\n');
	}
	return (get_line(tupile, nl_pos));
}

char	*get_next_line(int fd)
{
	static char	*tupile[2];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!tupile[0])
		tupile[0] = (char *)malloc(BUFFER_SIZE + 1);
	if (!tupile[0])
		return (NULL);
	return (work(fd, tupile));
}
