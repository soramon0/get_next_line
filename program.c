#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*data;

	data = get_next_line(0);
	if (!data)
	{
		printf("got null");
	}
	else
	{
		printf("got = %s", data);
	}
	return (0);
}
