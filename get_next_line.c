/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:45:02 by brdani            #+#    #+#             */
/*   Updated: 2024/11/16 06:55:20 by brdani           ###   ########.fr       */
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
	// extract depuis le buffer sur une ligne
	// tout nettoyer et free 
	return (line);
}
char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bt;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL);
		return (NULL);
	bt = 1;
	while (bt > 0)
	{
		bt = read(fd, buffer, BUFFER_SIZE);
		if (bt == -1)
		{
			free (buffer);
			free (stash);
			return (NULL);
		}
		buffer[bt] = 0;
		//Concatener la stash et le buffer et la libere (strjoin ?)
		stash = ft_strjoin(stash, buffer);
		free (stash);
		//Trouver le /n (strchr ?) et stopper la boucle car lue
		if (ft_strchr(stash, '\n'));
			bt--;       
	}
	free (buffer);
	return (stash);
}
