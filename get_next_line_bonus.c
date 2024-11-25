/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:50:16 by brdani            #+#    #+#             */
/*   Updated: 2024/11/25 17:53:09 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *stash, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	int		bt;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bt = 1;
	while (bt > 0)
	{
		bt = read(fd, buffer, BUFFER_SIZE);
		if (bt == -1)
		{
			free (stash);
			free (buffer);
			stash = NULL;
			buffer = NULL;
			return (stash);
		}
		buffer[bt] = '\0';
		stash = ft_join_free(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	return (str);
}

char	*clean_line(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || (stash[i] == '\n' && !stash[i + 1]))
	{
		free (stash);
		return (NULL);
	}
	str = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	while (stash[++i])
		str[j++] = stash[i];
	str[j] = '\0';
	free (stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, (sizeof(char)));
	stash[fd] = read_fd(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_line(stash[fd]);
	return (line);
}