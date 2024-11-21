/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:14:43 by brdani            #+#    #+#             */
/*   Updated: 2024/11/21 13:23:47 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char			*get_next_line(int fd);
char			*read_fd(int fd, char *stash);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t num, size_t size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_join_free(char *stash, char *buffer);
char			*extract_line(char *stash);
char			*clean_line(char *stash);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *str, int c, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

#endif