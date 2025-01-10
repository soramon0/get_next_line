/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

void	process(int fd, int fd2, int fd3)
{
	char	*data[3];

	data[0] = get_next_line(fd);
	printf("[%d]: %s", fd, data[0]);
	data[1] = get_next_line(fd2);
	printf("[%d]: %s", fd2, data[1]);
	data[2] = get_next_line(fd3);
	printf("[%d]: %s", fd3, data[2]);
	while (1)
	{
		if (!data[0])
			break ;
		else
			printf("[%d]: %s", fd, data[0]);
		free(data[0]);
		data[0] = get_next_line(fd);
	}
	free(data[1]);
	free(data[2]);
	printf("EOF\n");
}

int	main(void)
{
	int	makefile;
	int	get_line;
	int	get_line_bonus;

	makefile = open("Makefile", O_RDONLY);
	if (makefile == -1)
	{
		printf("could not open file\n");
		return (1);
	}
	get_line = open("get_next_line.c", O_RDONLY);
	if (get_line == -1)
	{
		printf("could not open file\n");
		return (1);
	}
	get_line_bonus = open("get_next_line_bonus.c", O_RDONLY);
	if (get_line_bonus == -1)
	{
		printf("could not open file\n");
		return (1);
	}
	process(makefile, get_line, get_line_bonus);
	return (0);
}
