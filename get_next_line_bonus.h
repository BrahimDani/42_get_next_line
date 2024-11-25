/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:48:57 by brdani            #+#    #+#             */
/*   Updated: 2024/11/25 17:49:51 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_join_free(char *stash, char *buffer);
char			*extract_line(char *stash);
char			*clean_line(char *stash);
void			ft_bzero(void *s, size_t n);

#endif