/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:45:02 by brdani            #+#    #+#             */
/*   Updated: 2024/11/20 10:37:01 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	// extract depuis le buffer sur une ligne
	// tout nettoyer et free 
	return (line);
}

char	*ft_join_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bt;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL);
		return (NULL);
	bt = 1;
	while (bt > 0)
	{
		bt = read(fd, buffer, BUFFER_SIZE);
		if (bt == -1)
		{
			free (stash);
			free (buffer);
			return (stash);
		}
		buffer[bt] = '\0';
		stash = ft_join_free(stash, buffer);
		if (ft_strchr(stash, '\n'));
			break;       
	}
	free (buffer);
	return (stash);
}

