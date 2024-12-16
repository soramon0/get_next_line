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

static char	*get_line(char *buf, ssize_t bytes)
{
	ssize_t	i;

	i = ft_strchr(buf, '\n');
	if (i == -1)
	{
		// read more
		return (NULL);
	}
	if (bytes - i != 0) {

	}
	return (ft_strdup(buf, i));
}

static char	*work(int fd)
{
	static char		buf[BUFFER_SIZE];
	ssize_t	bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (!bytes)
		return (NULL);
	return (get_line(buf, bytes));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (work(fd));
}
