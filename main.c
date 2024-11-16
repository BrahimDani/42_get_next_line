/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:25 by brdani            #+#    #+#             */
/*   Updated: 2024/11/14 08:07:41 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open ("test/simple", 0_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line = NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}