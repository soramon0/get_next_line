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

char	*get_next_line(int fd)
{
	unsigned int	buf_size;
	static char		buf[1024];
	int				bytes;

	buf_size = BUFFER_SIZE;
	if (buf_size == 0 || fd < 0)
		return (NULL);
	bytes = read(fd, buf, buf_size);
	if (bytes == 0 || bytes == -1)
		return (NULL);
	return (buf);
}
