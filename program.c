/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*data;
	int		fd;
	int		i;

	fd = open("Makefile", O_RDONLY);
	if (fd == -1)
	{
		printf("could not open file\n");
		return (1);
	}
	i = 3;
	while (i--)
	{
		data = get_next_line(fd);
		if (!data)
		{
			printf("got null\n");
			break ;
		}
		else
		{
			printf("%s", data);
		}
	}
	return (0);
}
