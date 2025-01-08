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

int	main(int argc, char *argv[])
{
	char	*data;
	int		fd;

	if (argc != 2){
		printf("not enough arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("could not open file\n");
		return (1);
	}
	printf("Reading %s file line by line in chunks of %d bytes...\n", argv[1], BUFFER_SIZE);
	data = get_next_line(fd);
	while (1)
	{
		if (!data)
		{
			printf("%s", data);
			printf("\n");
			break ;
		}
		else
			printf("%s", data);
		data = get_next_line(fd);
	}
	return (0);
}
